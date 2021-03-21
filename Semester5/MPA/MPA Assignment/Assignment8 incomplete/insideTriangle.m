function l = insideTriangle(t,x,y)
a =  sqrt( (t[0]-t[2])*(t[0]-t[2]) +  (t[1]-t[3])*(t[1]-t[3]))
    b = sqrt( (t[0]-t[4])*(t[0]-t[4]) +  (t[1]-t[5])*(t[1]-t[5]))
    c = sqrt( (t[2]-t[4])*(t[2]-t[4]) + (t[3]-t[5])*(t[3]-t[5]))
    s = (a + b + c)/2
    area_triangle =  sqrt(s*(s-a)*(s-b)*(s-c))

    x1 =  sqrt( (t[0]-x)*(t[0]-x) +  (t[1]-y)*(t[1]-y))
    x2 =  sqrt( (t[2]-x)*(t[2]-x) +  (t[3]-y)*(t[3]-y))
    x3 =  sqrt( (x-t[4])*(x-t[4]) +  (y-t[5])*(y-t[5]))
    s1 = (a+x1+x2)/2
    s2 = (c+x2+x3)/2
    s3 = (b+x1+x3)/2

    area_1 =  sqrt( abs(s1*(s1-a)*(s1-x1)*(s1-x2)))
    area_2 =  sqrt( abs(s2*(s2-c)*(s2-x2)*(s2-x3)))
    area_3 =  sqrt( abs(s3*(s3-b)*(s3-x1)*(s3-x3)))
    
    if (area_triangle == area_1+area_2+area_3)
        l= 1
    else
        l= 0
    end