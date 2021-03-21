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

#include "aLayer.h"

Define_Module(ALayer);

void ALayer::initialize()
{
    // TODO - Generated method body
    id = par("id");
    if(id==1)
    {
        A_PDU *msg = new A_PDU();
        msg->setId(1);
        msg->setType("Data");
        msg->setSource(1);
        msg->setDestination(2);
        send(msg, "al_dl_out");
    }
}

void ALayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    DL_PDU *msg1 = new DL_PDU();
    if(id==2 && msg1->getId() <= 10)
    {
        A_PDU *msg2 = new A_PDU();
        msg2->setId(msg1->getId());
        msg2->setType("Ack");
        msg2->setSource(2);
        msg2->setDestination(1);
        send(msg2, "al_dl_out");
    }
    else if(id==1 && msg1->getId() < 10)
    {
        A_PDU  *msg2 = new A_PDU();
        msg2->setId(msg1->getId()+1);
        msg2->setType("Data");
        msg2->setSource(1);
        msg2->setDestination(2);
        send(msg2, "al_dl_out");
    }
}
