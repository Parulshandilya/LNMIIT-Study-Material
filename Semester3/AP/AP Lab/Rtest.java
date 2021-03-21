/**** Class Rational for Rational number Operations ***/

class Rational
{
   int num;
   int deno;
   public void initialize()
   {
       num = 0;
       deno= 1;
   }
  
   public void initialize(int n, int d)
   {
       num = n;
       deno= d;
   }
   public void initialize(int n)
   {
       num = n;
       deno= 1;
   }
   public Rational addRational(Rational r)
   {
      Rational t = new Rational();
      int g;
      t.num =  num*r.deno + r.num*deno;
      t.deno = deno * r.deno;

      g = gcd(t.num, t.deno);
      t.num = t.num/g;
      t.deno = t.deno/g;
      return t;
   }

   public void displayRational()
   {
      System.out.print("\nRational Number is: ");
      System.out.println(num+"/"+deno);
   }
   public int gcd(int x, int y)
   {
      if(x%y==0)
        return y;

      else
       return gcd(y, x%y);
   }

}
class Rtest
{
  
   public static void main(String args[])
   {
     /* Rational r1= new Rational();
     Rational r2 = new Rational();
     Rational r3;
     r1.initialize(3,5);
     r2.initialize(5,7);
     r3 = r1.addRational(r2);
     r1.displayRational();
     r2.displayRational();
     r3.displayRational();*/
     int a;
     System.out.println("a="+a);
   }
}
