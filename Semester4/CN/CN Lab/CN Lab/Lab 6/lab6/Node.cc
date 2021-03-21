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

#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
	int INF = 999;
    nid =par("nId");
    if(nid == 0){
        cost[0] = 0;
        cost[1] = 5;
        cost[2] = 2;
        cost[3] = 3;
        cost[4] = INF;
        next[0]=0;
        next[1]=1;
        next[2]=2;
        next[3]=3;
        next[4]=-1;
    }
    else if(nid == 1){
        cost[0] = 5;
        cost[1] = 0;
        cost[2] = 4;
        cost[3] = INF;
        cost[4] = 3;
        next[0]=0;
        next[1]=1;
        next[2]=2;
        next[3]=-1;
        next[4]=4;
    }
    else if(nid == 2){
        cost[0] = 2;
        cost[1] = 4;
        cost[2] = 0;
        cost[3] = INF;
        cost[4] = 4;
        next[0]=0;
        next[1]=1;
        next[2]=2;
        next[3]=-1;
        next[4]=4;
    }
    else if(nid == 3){
        cost[0] = 3;
        cost[1] = INF;
        cost[2] = INF;
        cost[3] = 0;
        cost[4] = INF;
        next[0]=0;
        next[1]=-1;
        next[2]=-1;
        next[3]=3;
        next[4]=-1;
    }
    else if(nid == 4){
        cost[0] = INF;
        cost[1] = 3;
        cost[2] = 4;
        cost[3] = INF;
        cost[4] = 0;
        next[0]=-1;
        next[1]=1;
        next[2]=2;
        next[3]=-1;
        next[4]=4;
     }
    start = new cMessage("start");
    WATCH(cost[0]);
    WATCH(cost[1]);
    WATCH(cost[2]);
    WATCH(cost[3]);
    WATCH(cost[4]);
    WATCH(next[0]);
    WATCH(next[1]);
    WATCH(next[2]);
    WATCH(next[3]);
    WATCH(next[4]);
    scheduleAt(0,start);

}

void Node::handleMessage(cMessage *msg)
{
    if(msg->isSelfMessage()){
        R_PDU *table = new R_PDU();
        for(int i=0;i<5;i++){
            table->setPcost(i,cost[i]);
            table->setPnext(i,next[i]);
        }
        for(int i=0;i<5;i++){
            if(table->getPcost(i)>0 && table->getPcost(i)!=INF)
                send(table->dup(),"g$o",next[i]);
        }
    }
    else{
        arrival = msg->getArrivalGate();
        int gateNumber = arrival->getIndex();
        char text[32];
        sprintf(text, "entering node:%c", 'A'+gateNumber);
        bubble(text);
        R_PDU *rpdu = check_and_cast<R_PDU*>(msg);
        int flag=0;
        int edgeCost = cost[gateNumber];
        for(int i=0;i<5;i++){
            if(cost[i] > rpdu->getPcost(i)+edgeCost)
            {
                cost[i]=rpdu->getPcost(i)+edgeCost;
                next[i]=gateNumber;
                flag=1;
            }
        }
        if(flag == 1){
            scheduleAt(simTime(),start);
        }
    }
}
