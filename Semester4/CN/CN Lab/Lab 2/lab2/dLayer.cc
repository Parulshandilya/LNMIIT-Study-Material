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

#include "dLayer.h"

Define_Module(DLayer);

void DLayer::initialize()
{
    // TODO - Generated method body
    id = par("id");
}

void DLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(!strcmp(msg->getArrivalGate()->getName(),"al_dl_in") && id==1)
        {
            A_PDU *msg1 = check_and_cast<A_PDU*> (msg);
            DL_PDU *msg2 = new DL_PDU();
            msg2->encapsulate(msg1);
            send(msg2, "dl_p_out");
        }
    else if(!strcmp(msg->getArrivalGate()->getName(), "p_dl_in") && id == 2)
    {
        DL_PDU *msg1 = check_and_cast<DL_PDU*> (msg);
        A_PDU *msg2 = new A_PDU();
        msg2 = check_and_cast<A_PDU*> (msg1->decapsulate());
        send(msg2, "dl_al_out");
    }
    else if(!strcmp(msg->getArrivalGate()->getName(), "al_dl_in") && id == 2)
    {
        A_PDU *msg1 = check_and_cast<A_PDU*> (msg);
        DL_PDU *msg2 = new DL_PDU();
        msg2->encapsulate(msg1);
        send(msg2, "dl_p_out");
    }
    else if(!strcmp(msg->getArrivalGate()->getName(), "p_dl_in") && id == 1)
    {
        DL_PDU *msg1 = check_and_cast<DL_PDU*> (msg);
        A_PDU *msg2 = new A_PDU();
        msg2 = check_and_cast<A_PDU*> (msg1->decapsulate());
        send(msg2, "dl_al_out");
    }
}
