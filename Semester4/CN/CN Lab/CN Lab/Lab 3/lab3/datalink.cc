//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "datalink.h"

Define_Module(Datalink);

void Datalink::initialize()
{
    id = 0;
    toAl = gate("toAl");
    toPl = gate("toPl");
    fromAl = gate("fromAl");
    fromPl = gate("fromPl");
    timeout = 5.0;
    buf = NULL;
    timeoutEvent= new cMessage("timeoutEvent");
}

void Datalink::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage()){
        EV << "Timeout expired, resending message and restarting timer\n";
        send(buf->dup(),toPl);
        scheduleAt(simTime()+timeout,timeoutEvent);
    }
    if(msg->getArrivalGate() == fromAl){
        double delay;
        if(uniform(0,1) < 0.3){
            delay = 2.0;
        }else{
            delay = 1.0;
        }
        A_PDU *apdu = check_and_cast<A_PDU *>(msg);
        DL_PDU *pkt = new DL_PDU();
        pkt->encapsulate(apdu);
        buf = pkt->dup();
        buf->setId(0);
        id++;
        sendDelayed(buf->dup(),delay,toPl);
        if(apdu->getType() == DATA)
            scheduleAt(simTime()+timeout,timeoutEvent);

    }
    if(msg->getArrivalGate() == fromPl){
        DL_PDU *dlpdu = check_and_cast<DL_PDU*>(msg);
        if(dlpdu->getId() == 0){
            double delay;
            if(uniform(0,1) < 0.4){
                delay = 2.0;
            }else{
                delay = 1.0;
            }
            A_PDU *pkt = check_and_cast<A_PDU*>(dlpdu->decapsulate());
            DL_PDU *ack = new DL_PDU();
            ack->setId(1);
            id++;
            if(pkt->getType() == ACK){
                EV << "Timer cancelled.\n";
                cancelEvent(timeoutEvent);
            }
            sendDelayed(pkt,delay,toAl);
            send(ack,toPl);

        }
        else if(dlpdu->getId()==1){
            delete dlpdu;

        }

    }
}
