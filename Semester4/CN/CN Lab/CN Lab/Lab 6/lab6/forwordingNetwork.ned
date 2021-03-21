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

package lab6;

network ForwordingNetwork
{
    @display("bgb=378,243");
    submodules:
        A: Node {
            nId = 0;
            @display("p=60,51");
        }
        B: Node {
            nId = 1;
            @display("p=324,51");
        }
        C: Node {
            nId = 2;
            @display("p=169,130");
        }
        D: Node {
            nId = 3;
            @display("p=60,188");
        }
        E: Node {
            nId = 4;
            @display("p=324,188");
        }
    connections allowunconnected:
        A.g[1] <-->{delay = 3ms;}<--> B.g[0];
        A.g[2] <-->{delay = 2ms;}<--> C.g[0];
        A.g[3] <-->{delay = 3ms;}<--> D.g[0];
        B.g[2] <-->{delay = 4ms;}<--> C.g[1];
        B.g[4] <-->{delay = 3ms;}<--> E.g[1];
        C.g[4] <-->{delay = 4ms;}<--> E.g[2];
}
