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

#include "PhysicalLayer.h"
#include "P_PDU_m.h"
#include "DL_PDU_m.h"
Define_Module(PhysicalLayer);

void PhysicalLayer::initialize()
{
    // TODO - Generated method body
            FromDataLink=gate("FromDataLink");
            ToDataLink=gate("ToDataLink");
            ToMedium=gate("ToMedium");
            FromMedium=gate("FromMedium");

}

void PhysicalLayer::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->getArrivalGate()==FromDataLink)
           { DL_PDU* p = check_and_cast<DL_PDU*>(msg);
           P_PDU* ms = new P_PDU();
           ms->encapsulate(p);
           send(ms,ToMedium);
           }
    else if (msg->getArrivalGate()==FromMedium)
            {
                P_PDU* p = check_and_cast<P_PDU*>(msg);
                send(p->decapsulate(),ToDataLink);
            }

}
