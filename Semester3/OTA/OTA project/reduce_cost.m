A=[4000 5000
   6000 3700
   -2     3];
b=[60000
   71000
   0];
ub=Inf(2,1);
lb=zeros(2,1);
lb(1)=1;
lb(2)=1;
ub(1)=10;
ub(2)=12;
intcon=1:2;
Aeq = [0 0
       0 0
       0 0];
 beq = [0
        0
        0];
  f=[1 1];
  [x]=intlinprog(f,intcon,A,b,Aeq,beq,lb,ub);
  
 