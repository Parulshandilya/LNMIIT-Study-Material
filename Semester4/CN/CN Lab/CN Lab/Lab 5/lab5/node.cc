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

#include "node.h"
#include "map"

using namespace std;

Define_Module(Node);

void Node::initialize()
{
    // TODO - Generated method body

    m.clear();

    id = par("id");
    source = par("source");
    destination = par("destination");

    in[0] = gate("in", 0);
    in[1] = gate("in", 1);
    in[2] = gate("in", 2);

    out[0] = gate("out", 0);
    out[1] = gate("out", 1);
    out[2] = gate("out", 2);

    //write some code to use gates;


    //map->first : denotes the destination node.
    //map->second : denotes the destination node's port[via index].

    if(id == 1)
    {
        m[2] = 0;
        m[3] = 1;
        m[4] = 2;
        m[5] = 1;
    }
    if(id == 2)
    {
        m[1] = 0;
        m[3] = 1;
        m[4] = 0;
        m[5] = 2;
    }
    if(id == 3)
    {
        m[1] = 0;
        m[2] = 1;
        m[4] = 0;
        m[5] = 2;
    }
    if(id == 4)
    {
        m[1] = 0;
        m[2] = 0;
        m[3] = 0;
        m[5] = 0;
    }
    if(id == 5)
    {
        m[1] = 1;
        m[2] = 0;
        m[3] = 1;
        m[4] = 1;
    }
    if(id == source)
    {
        cMessage *start = new cMessage();
        scheduleAt(0, start);
    }
}

void Node::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    if(msg->isSelfMessage())
    {
        cMessage *newmsg = new cMessage("msg");
        int out_index = m[destination];
        send(newmsg, out[out_index]);
    }
    else if(id == destination)
    {
        char lol[] = "Message is received\n";
        bubble(lol);
    }
    else
    {
        int out_index = m[destination];
        send(msg, out[out_index]);
    }
}
