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

package lab2;

module Node
{
    parameters: 
        int nid;
    gates:
        input in;
        output out;    
        
    submodules:
        app : ALayer{id = nid;}
        data : DLayer{id = nid;} 
        physical : PLayer{id = nid;}
   
    connections:
        app.al_dl_out --> data.al_dl_in;
        app.dl_al_in <-- data.dl_al_out;
        
        data.dl_p_out --> physical.dl_p_in;
        data.p_dl_in <-- physical.p_dl_out;
        
        physical.p_n_out --> out;
        physical.n_p_in <-- in;
}
