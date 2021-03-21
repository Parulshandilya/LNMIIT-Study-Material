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

package lab3;

module Node
{
    parameters:
        int nId;
    gates:
        input in;
        output out;
    submodules:
     	al: Application{nid=nId;}
     	dl: Datalink{nid=nId;}
     	pl:	Physical{nid=nId;}
    connections:
        al.fromDl<--dl.toAl;
        al.toDl-->dl.fromAl;
        dl.fromPl<--pl.toDl;
        dl.toPl-->pl.fromDl;
        pl.fromNetwork<--in;
        pl.toNetwork-->out;
        
   
}
