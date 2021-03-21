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

#include "application.h"

Define_Module(Application);

void Application::initialize()
{
    nid = par("nid");
    counter = 0;
    toDl = gate("toDl");
    alpha = 'A';

    if(nid == 1){
        cMessage *msg = new cMessage();
        scheduleAt(0,msg);

    }
}

void Application::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage()){
        A_PDU *pkt = new A_PDU();
        pkt->setMId(counter);
        pkt->setType(DATA);
        pkt->setAlphabet(alpha+counter);
        counter++;
        send(pkt,toDl);
    }
    else{
        A_PDU *pkt = check_and_cast<A_PDU *>(msg);
        if(counter<26 && pkt->getType() == ACK){
            pkt->setMId(counter);
            pkt->setType(DATA);
            pkt->setAlphabet(alpha+counter);
            counter++;
            send(pkt,toDl);
        }
        else if(pkt->getType() == DATA){
            pkt->setType(ACK);
            send(pkt,toDl);
        }
    }
}
