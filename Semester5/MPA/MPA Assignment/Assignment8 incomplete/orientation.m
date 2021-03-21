function l = orientation( x1,  y1,  x2,  y2,  px,  py)
	orientation = ((x2 - x1) * (py - y1)) - ((px - x1) * (y2 - y1))

	if(orientation > 0)
		l= 1
	else if(orientation < 0)
		l= -1
	else
		l= 0
 end
