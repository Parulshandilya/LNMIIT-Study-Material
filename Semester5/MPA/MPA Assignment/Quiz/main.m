clear all;
img = imread('20180911_114013(1)(1).jpg');
img = im2double(img);
figure(1);
imshow(img);
[c r p] = impixel; % for extracting the pixels
figure(2);
imshow(img);
% for creating the rectangle
hold on;
plot([c;c(1)],[r;r(1)],'r','Linewidth',2);
text(c(1),r(1)+20,'0, 11','Color','y');
text(c(2),r(2)+20,'11, 11','Color','y');
text(c(3),r(3)-20,'11, 0','Color','y');
text(c(4),r(4)-20,'0, 0','Color','y');
hold off;
% for pts1
% points that should have same y coordinates
x11 = c(1);
y11 = r(1);
x12 = c(2);
y12 = r(2);
%points that should have same x coordinates as previous points
x21 = c(3);
y21 = r(3);
x22 = c(4);
y22 = r(4);
%assuming the relationship and generating the points
x11h = x11;
y11h = y11;
x12h = x12;
y12h = y11;
x21h = x12;
y21h = y21;
x22h = x11;
y22h = y21;
%solving 8 linear equations
syms h00 h01 h02 h10 h11 h12 h20 h21 h22
h22 = 1;
   e1= (h00*x11 + h01*y11 + h02)/(h20*x11 + h21*y11 + h22)==x11h; 
   e2=(h10*x11 + h11*y11 + h12)/(h20*x11 + h21*y11 + h22) == y11h;
   e3 = (h00*x12 + h01*y12 + h02)/(h20*x12 + h21*y12 + h22)==x12h; 
   e4 = (h10*x12 + h11*y12 + h12)/(h20*x12 + h21*y12 + h22)==y12h;
   e5 = (h00*x21 + h01*y21 + h02)/(h20*x21 + h21*y21 + h22)==x21h;
   e6 = (h10*x21 + h11*y21 + h12)/(h20*x21 + h21*y21 + h22)==y21h;
   e7 = (h00*x22 + h01*y22 + h02)/(h20*x22 + h21*y22 + h22)==x22h; 
   e8 = (h10*x22 + h11*y22 + h12)/(h20*x22 + h21*y22 + h22)==y22h;
   
    sol = solve([e1, e2, e3, e4, e5, e6, e7, e8], [ h00,h01, h02,h10,h11,h12,h20,h21]);
    h00Sol = sol.h00;
    h01Sol = sol.h01;
    h02Sol = sol.h02;
    h10Sol = sol.h10;
    h11Sol = sol.h11;
    h12Sol = sol.h12;
    h20Sol = sol.h20;
    h21Sol = sol.h21;
    %storing the obtained h values in the homogeneous matrix
    h = zeros(3,3);
    h(1,1) = (h00Sol);
    h(1,2) = (h01Sol);
    h(1,3) = (h02Sol);  
    h(2,1) = (h10Sol);
    h(2,2) = (h11Sol);
    h(2,3) = (h12Sol);
    h(3,1) = (h20Sol);
    h(3,2) = (h21Sol);
    h(3,3) = (h22);
    %size of the image
    [x,y,~] = size(img);
    x
    y
    %displaying the homogeneous matrix
    h
%storing the obtained values in the new image
for i=1:432
    for j=1:576
        v1 = [j;i;1];
        v2 = h*v1;
        v3 =v2/v2(3,1);
        if (v3(1,1) <0 || v3(2,1)<0 || v3(3,1)<0)
           continue;
        else     
            res(round(1+v3(2,1)),round(1+v3(1,1)))=img(i,j);
        end
    end
end
figure(4);
imshow(res);
figure('Name','Resultant Image','NumberTitle','off');imshow(res);
