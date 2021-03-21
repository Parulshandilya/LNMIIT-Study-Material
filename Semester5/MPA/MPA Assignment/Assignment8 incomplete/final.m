clc
close all

% Providing the Source(im1) and Destination(im2) Images.
im1=imread('1.jpg');
im2=imread('2.jpg');
figure
imshow(im1);

% Resizing the images if necessary(Both the images should be equal in size) 
im2=imresize(im2,[size(im1,1) size(im1,2)]);
figure
imshow(im2);


%bush coordinates
bx=[1,216,307,264,499,1,499]
by=[1,205,194,262,499,499,1]
%clnton points
cx=[1,181,279,226,499,1,499]
cy=[1,252,244,315,499,499,1]

% Number of intermediate images required
n=8;

% Running the for loop through the rows and columns of the pixel matrix(of the images)
for i = 1:n
    im3(:,:,1)=imgBetween(im1(:,:,1),im2(:,:,1),n,i);
    im3(:,:,2)=imgBetween(im1(:,:,2),im2(:,:,2),n,i);
    im3(:,:,3)=imgBetween(im1(:,:,3),im2(:,:,3),n,i);
    figure
    imshow(uint8(im3))
    pause(0.1)
end


