%Initialize variables G,B,W X=[G,B,W]
X=rand(1,3);

%Constraints maximum fat: .27G + .12B + 0.06W <=0.1 , minimum protein: 0.0G + 0.08B + 0.56 W >=0.007 , 
%maximum protein: 0.0G + 0.08B + 0.56W <=0.015 , minimum fiber: 0.002G + 0.12B + 0.08W >=0.06
%declare coefficient matrix

A=[0.27,0.12,0.06;0.0,-0.08,-0.56;0.0,0.08,0.56;-0.002,-0.12,-0.08];
%declare b

b=[0.1;-0.007;0.015;-0.06];

fprintf('Cost at initial  (X): %f\n', costFunction(X));

fprintf('\nProgram paused. Press enter to continue.\n');
pause;

x = fmincon(@(t)(costFunction(t)),X,A,b);
G=x(1);
B=x(2);
W=x(3);

%Minimum cost 
Z = costFunction(x);

fprintf('Cost at optimized (x): %f\n', Z);
 





