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

#include "ApplicationLayer.h"
#include "A_PDU_m.h"
Define_Module(ApplicationLayer);

void ApplicationLayer::initialize()
{
    nid=par("aid");
    FromDataLink=gate("FromDataLink");
    ToDataLink=gate("ToDataLink");
    count=0;
   if(nid==1){cMessage * event = new cMessage();
       scheduleAt(0,event);
       }
}

void ApplicationLayer::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage())
    {
        count++;
        A_PDU* data=new A_PDU();
        data->setId(1);
        data->setSource(1);
        data->setDestination(2);
        data->setType("Data");
        send(data,ToDataLink);
    }
    else
    {
        if(count<10)
        {
            A_PDU* data=new A_PDU();
            if(data->getType(),"Acck")
            {
                    count++;

                    data->setId(count);
                    data->setSource(1);
                    data->setDestination(2);
                    data->setType("Data");
                    send(data,ToDataLink);
            }
            else if(data->getType(),"Data")
            {
                    data->setType("Data");
                    send(data,ToDataLink);
            }

        }
    }

}
