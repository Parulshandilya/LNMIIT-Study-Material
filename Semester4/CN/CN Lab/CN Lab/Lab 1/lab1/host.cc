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

#include "host.h"
#include "pkt_m.h"

Define_Module(Host);

void Host::initialize()
{
    ind = par("id");

    if(!strcmp("h1" , getName())){
           Pkt *msg = new Pkt();
           msg->setId(1);
           msg->setSource(1);
           msg->setDestination(2);
           msg->setType("Data");
           send(msg, "out");
        }
}

void Host::handleMessage(cMessage *msg)
{

    // TODO - Generated method body
    Pkt * msg1 = (Pkt *)msg;
        if(msg1->getSource() == 1 and msg1->getId() <= 10){
            msg1->setType("Ack");
            msg1->setSource(2);
            msg1->setDestination(1);
            send(msg1, "out");
        }
        else if(msg1->getSource() == 2 and msg1->getId() < 10){
            Pkt * new_m = new Pkt();
            new_m->setId(msg1->getId()+1);
            new_m->setType("Data");
            new_m->setSource(1);
            new_m->setDestination(2);
            send(new_m, "out");
        }
}

