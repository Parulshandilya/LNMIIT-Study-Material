function p= morphTriangle(sI, dI, sT, dT, iT, new_img,kbyn):

	for i=0:sI.shape[0]
		for j=0:sI.shape[1]
			for z=0:8
				o1 = orientation(iT[z][0], iT[z][1], iT[z][2], iT[z][3], i, j)
				o2 = orientation(iT[z][2], iT[z][3], iT[z][4], iT[z][5], i, j)
				o3 = orientation(iT[z][4], iT[z][5], iT[z][0], iT[z][1], i, j)
				if(o1 == o2 and o2 == o3)
					inside = 1
				else
					inside = 0
    end
				if(inside == 1):

					a=[[iT[z][2]-iT[z][0],iT[z][4]-iT[z][0]],[iT[z][3]-iT[z][1],iT[z][5]-iT[z][1]]]
					b=[[i-iT[z][0]],[j-iT[z][1]]]                      
					[al, be]=solve(a, b)
					
					x_src= (int) (sT[z][0] + al*(sT[z][2]-sT[z][0]) + be*(sT[z][4]-sT[z][0]))
					y_src= (int) (sT[z][1] + al*(sT[z][3]-sT[z][1]) + be*(sT[z][5]-sT[z][1]))
					x_dst= (int) (dT[z][0] + al*(dT[z][2]-dT[z][0]) + be*(dT[z][4]-dT[z][0]))
					y_dst= (int) (dT[z][1] + al*(dT[z][3]-dT[z][1]) + be*(dT[z][5]-dT[z][1]))

					k = 10 * kbyn
					r = ((10-k)*sI[x_src][y_src][0] +k*dI[x_dst][y_dst][0])/10
					g = ((10-k)*sI[x_src][y_src][1] +k*dI[x_dst][y_dst][1])/10
					b = ((10-k)*sI[x_src][y_src][2] +k*dI[x_dst][y_dst][2])/10

					
					new_img[i][j] = [r,g,b]
   	end
   end
  end
 end
 
     p= new_img
