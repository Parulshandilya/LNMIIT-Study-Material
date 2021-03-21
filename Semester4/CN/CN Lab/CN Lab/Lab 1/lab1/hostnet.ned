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

package lab1;

//
// TODO auto-generated type
//
network Hostnode
{
    	submodules:
        h1: Host {
            id = 1;
            @display("p=35,30");
        }
        h2: Host {
			id = 2;
            @display("p=202,30");
        }
    connections:
        h1.in <-- h2.out;
        h1.out --> h2.in;
}