
pic = rgb2gray(imread('moon.jpg'));

pad = padarray(pic,[1,1],0,'both');

final = zeros(size(pic));
for j=2:435
    for i=2:458
        final(i-1,j-1) = (pad(i-1,j) + pad(i,j-1) + pad(i-1,j+1) + pad(i-1,j-1) + pad(i+1,j-1) + pad(i,j+1) + pad(i+1,j) + pad(i+1,j+1)) - (pad(i,j)*(8));
    end
end

figure(1),imshow(pic);
final = im2uint8(final);
final = imsubtract(pic,final);
figure(2),imshow(final);
% final --- sharpened image

z = imhist(final);

x = 1;
y = 2;
for i=3:256
    if (z(i) > z(x)) && (z(i) < z(y))
        x = i;
    elseif (z(i) < z(x)) && (z(i) > z(y))
        y = i;
    elseif (z(i) > z(x)) && (z(i) > z(y))
        if (z(x)>z(y))
            y = i;
        else
            x = i;
        end
    end
end

thresh = 40;

for j=1:434
    for i=1:457
        if final(i,j) > thresh
            final(i,j) = 255;
        else
            final(i,j) = 0;
        end
    end
end




% Labeling

p = final;

label = 0;
for i = 2:457
    for j = 2:434
        if (p(i,j) ~= 0)
            a = p(i-1,j); %Left
            b = p(i,j-1); %top
            
            if (a==b)
                if (a==0)
                    label = label + 1;
                    p(i,j) = label;
                    
                else
                    p(i,j) = a;
                end
            else
                if (a==0)
                    p(i,j) = b;
                else 
                    if (b==0)
                        p(i,j) = a;
                
                    else
                        if (a<b)
                            p(i,j) = a;
                            p(p==b) = a;
                        else
                            p(i,j) = b;
                            p(p==1) = b;
                        end
                    end
                end
           
                        
            end
        end
    end
end

original = p;
label = max(max(original));
index =2;
count =0;
maxi = 0;
for h = 1:923
    for i=2:456
        for j = 2:433
            if(original(i,j)==h)
                count = count+1;
            end
        end
    end
    if(count>maxi)
        maxi = count;
        
        index = h;
    end
    count = 0;
end
original(original~=index)=0;
original(original==index)=255;

figure(3),imshow(original);

% -- Bounding box --
%{ 
red box
figure(4),imshow(final);
temp = regionprops(final, 'BoundingBox' );
for ind = 1 : length(temp)
  thisBB = temp(ind).BoundingBox;
  rectangle('Position', [thisBB(1),thisBB(2),thisBB(3),thisBB(4)],...
  'EdgeColor','r','LineWidth',2 )
end
%}
