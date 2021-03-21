A=[-4 -5
   -3 -4];
b=[-28
   -70];
ub=[12;12];
lb=[1;1];
intcon=1:2;
Aeq = [0 0
       0 0];
 beq = [0
        0];
  f=[1 1];
  [y]=intlinprog(f,intcon,A,b,Aeq,beq,lb,ub);
 
  z=f*y;