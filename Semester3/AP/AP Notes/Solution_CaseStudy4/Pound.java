public class Pound extends Currency 
{
	static private double conversionRate;

	public Pound(int notes, int coins,int vnotes,int vcoins)
	{
	
        super(notes,coins,vnotes,vcoins);
	}	
	static
	{
		conversionRate = 78.0; // static block to initialize conversionRate
	}	
	public double compute()
	{
		double total = super.compute();
		return total;
	}
    public double convertToRupees()
	{
		return this.compute()*conversionRate;
	}
	public void print()
	{
		//super.print();
		System.out.println(this);
	}
	public static void modifyConversionRate(double rate)
	{
		conversionRate= rate;
	}
	
	public String toString()  // to override the method toString() of class Object
	{                         // To convert the class instance variable in a string
	    return super.toString()+"\n Conversion Rate:"+conversionRate;
	}
	
	
}