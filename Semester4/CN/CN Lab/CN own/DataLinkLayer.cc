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

#include "DataLinkLayer.h"
#include "DL_PDU_m.h"
#include "A_PDU_m.h"
Define_Module(DataLinkLayer);

void DataLinkLayer::initialize()
{

        FromApplication=gate("FromApplication");
        ToApplication=gate("ToApplication");
        ToPhysical=gate("ToPhysical");
        FromPhysical=gate("FromPhysical");
}

void DataLinkLayer::handleMessage(cMessage *msg)
{
    if(msg->getArrivalGate()==FromApplication)
       {
           A_PDU* data=check_and_cast<A_PDU*>(msg);
           DL_PDU* endata=new DL_PDU();
           endata->encapsulate(data);
           endata->setId(0);
           endata->setType(data->getType());
           endata->setDestination(data->getDestination());
           endata->setSource(data->getSource());
           send(endata,ToPhysical);
       }
    else
    {
           DL_PDU* data=check_and_cast<DL_PDU*>(msg);

               A_PDU* dedata=check_and_cast<A_PDU*>(data->decapsulate());
               send(dedata,ToApplication);


           }



}
