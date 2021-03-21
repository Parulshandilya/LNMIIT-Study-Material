
class Matrix
{
     int mat[][];   // in Java we dont specify the size of array rather we allocate the size dynamically  
      int row;   // We dont give any value to these variables here
     int col;

   /*  Method to initialize dimentions of matrix */
     public void initialize(int r, int c)
       {
            mat = new int [r][c];   //   dynamic allocation of memory to array "a"
            row = r;
            col =  c;
       }

/*   Method to store some arbitrary values in matrix */

      public void initializeArray()
      {
          int i,j;
          for(i=0;i<row; i++)
             for(j =0 ; j<col;j++)
                 mat[i][j] = i+j+2;
       }

/*  In some future class we will discuss how to take input from keyboard */                 

/* Method to display diagonal values of a matrix  */

     public void displayDiagonal()
       {
           int i,j;
           System.out.print("/***Diagonal Elements***/\n");
            for(i=0;i<row; i++)
                   System.out.println(mat[i][i]+"\t");
        }
 
/*  Method to find transopse of a matrix  */

     public Matrix transpose()
      {
int i,j;
         
 Matrix t= new Matrix();    //  Created a temporary object of class matrix to store transpose of given matrix
           t.initialize(col,row);        // to create the array of dimention( col, row) because transpose of [3][4] is [4][3]
           
            for(i=0;i<row; i++)
                for(j =0 ; j<col;j++)
                   t.mat[j][i] = mat[i][j];

            return t;
       }

/*   Method to calculate trace of a matrix
      public int traceMatrix()
       {
            int i;

            int trace =0;
          
            if(row == col)   // Trace can be calulated only if the matrix is square matrix
              {
                  for(i=0;i<row; i++)
                      trace = trace + mat[i][i];
                  return trace;
               }
             else 
                 {
                             System.out.println(" Matrix is not a squarematrix so trace is not possible");
                             System.exit();  // It terminates the Java program
                 }
          }

/***  Method to display Matrix  ***/

        public void displayMatrix()
         {
               int i,j;
               System.out.print("/***Matrix Contents:***/\n");
               for(i=0;i<row;i++)
                 {
                         for(j=0;j<col;j++)
                              System.out.print(mat[i][j]+"\t");
                         System.out.print("\n");
                 }
          }

}  /****  Class Matrix is over here   ****/


/***  Main class   ****/


 class  MatrixTest
{
     public static void main(String args[])
        {

             Matrix a =  new Matrix();   // Create an object of matrix class
             Matrix b =  new Matrix();  //  Create another object to hold Transpose of Matraix "a"
 
             a.initialize(3,4);
             a.initializeArray();
             a.displayMatrix(); // To display contents of matrix "a"

             a.displayDiagonal(); // To display diagonal elements of "a"

             b = a.transpose();  // will transpose the matrix "a" and store in "b"
            
             b.displayMatrix();   // Will display the matrix "b"

        }
}
                     
            


        
         
  
 
      