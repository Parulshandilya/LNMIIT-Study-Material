function warp_im = imgBetween(im1,im2,n,i)


for row=1:size(im1,1)
    for col=1:size(im2,2)
        q=double(im1(row,col));
        p=double(im2(row,col));
        
% The intermediate(im3) image is a combination of the Source Image and Destination Image        
        im3(row,col)=p +(1-i/n)*(q-p);
     end
  end
end
warp_im=im3
%a=i/n;
%xm=(1-a)*xi+a*xj
%ym=(1-a)*yi+a*yj
%M(xm,ym)=(1-a)*img1(xi,yi)+a*img2(xj,yj)
