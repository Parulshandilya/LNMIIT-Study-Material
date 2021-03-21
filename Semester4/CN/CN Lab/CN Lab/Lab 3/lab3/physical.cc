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

#include "physical.h"

Define_Module(Physical);

void Physical::initialize()
{
    toDl = gate("toDl");
    toNetwork = gate("toNetwork");
    fromDl = gate("fromDl");
    fromNetwork = gate("fromNetwork");
}

void Physical::handleMessage(cMessage *msg)
{
    if(msg->getArrivalGate() == fromDl){
        if(uniform(0,1) < 0.1){
            delete msg;
        }else{
            DL_PDU *dlpdu = check_and_cast<DL_PDU*>(msg);
            P_PDU *pkt = new P_PDU();
            pkt->encapsulate(dlpdu);
            send(pkt,toNetwork);
        }
        }
        if(msg->getArrivalGate() == fromNetwork){
            if(uniform(0,1) < 0.15){
                delete msg;
            }else{
                P_PDU *ppdu = check_and_cast<P_PDU*>(msg);
                DL_PDU *pkt = check_and_cast<DL_PDU*>(ppdu->decapsulate());
                send(pkt,toDl);
            }
        }
}
