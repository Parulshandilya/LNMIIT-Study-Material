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

#include "pLayer.h"

Define_Module(PLayer);

void PLayer::initialize()
{
    // TODO - Generated method body
    id = par("id");
}

void PLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(!strcmp(msg->getArrivalGate()->getName(), "dl_p_in") && id == 1)
    {
        DL_PDU *msg1 = check_and_cast<DL_PDU*> (msg);
        P_PDU *msg2 = new P_PDU();
        msg2->encapsulate(msg1);
        send(msg2, "p_n_out");
    }
    else if(!strcmp(msg->getArrivalGate()->getName(), "n_p_in") && id == 2)
    {
        P_PDU *msg1 = check_and_cast<P_PDU*> (msg);
        DL_PDU *msg2 = new DL_PDU();
        msg2 = check_and_cast<DL_PDU*>(msg1->decapsulate());
        send(msg2,"p_dl_out");
    }
    else if(!strcmp(msg->getArrivalGate()->getName(), "dl_p_in") && id == 2)
    {
        DL_PDU *msg1 = check_and_cast<DL_PDU*> (msg);
        P_PDU *msg2 = new P_PDU();
        msg2->encapsulate(msg1);
        send(msg2, "p_n_out");
    }
    else if(!strcmp(msg->getArrivalGate()->getName(), "n_p_in") && id == 1)
    {
        P_PDU *msg1 = check_and_cast<P_PDU*> (msg);
        DL_PDU *msg2 = new DL_PDU();
        msg2 = check_and_cast<DL_PDU*>(msg1->decapsulate());
        send(msg2, "p_dl_out");
    }
}
