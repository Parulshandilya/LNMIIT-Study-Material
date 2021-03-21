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

package lab5;

network ForwardingNetwork
{
    @display("bgb=276,386");
    
    submodules:
        A: Node {
            id = 1;
            @display("p=21,74");
        }
        B: Node {
            id = 2;
            @display("p=241,74");
        }
        C: Node {
            id = 3;
            @display("p=124,198");
        }
        D: Node {
            id = 4;
            @display("p=21,309");
        }
        E: Node {
            id = 5;
            @display("p=241,309");
        }

    connections allowunconnected:
        A.out[0] --> {  delay = 500ms; } --> B.in[0];
        A.in[0] <-- {  delay = 500ms; } <-- B.out[0];

        A.out[1] --> {  delay = 200ms; } --> C.in[0];
        A.in[1] <-- {  delay = 200ms; } <-- C.out[0];

        A.out[2] --> {  delay = 300ms; } --> D.in[0];
        A.in[2] <-- {  delay = 300ms; } <-- D.out[0];

        B.out[1] --> {  delay = 400ms; } --> C.in[1];
        B.in[1] <-- {  delay = 400ms; } <-- C.out[1];

        B.out[2] --> {  delay = 300ms; } --> E.in[0];
        B.in[2] <-- {  delay = 300ms; } <-- E.out[0];

        C.out[2] --> {  delay = 400ms; } --> E.in[1];
        C.in[2] <-- {  delay = 400ms; } <-- E.out[1];
}
