public class Rupee extends Currency 
{
	static private double conversionRateToDollar;
	static private double conversionRateToPound;
	

	public Rupee(int notes, int coins,int vnotes,int vcoins)
	{
	
        super(notes,coins,vnotes,vcoins);
	}	
	static
	{
		conversionRateToDollar = 0.50; // static block to initialize conversionRate
		conversionRateToPound = 0.78;
	}
	public double compute()
	{
		double total = super.compute();
		return total;
	}
    public double convertToDollar()
	{
		return this.compute()*conversionRateToDollar;
	}
	public double convertToPound()
	{
		return this.compute()*conversionRateToPound;
	}
	public double convertToRupees()
	{
		return this.compute()*1;
	}
	public void print()
	{
		//super.print();
		System.out.println(this);
	}
	
	public static void modifyConversionRateToDollar(double rate)
	{
		conversionRateToDollar= rate;
	}
	public static void modifyConversionRateToPound(double rate)
	{
		conversionRateToPound= rate;
	}
	
	public String toString()  // to override the method toString() of class Object
	{                         // To convert the class instance variable in a string
	    return super.toString()+"\n Conversion Rate To Dollar:"+conversionRateToDollar+"\nConversion Rate to Pound:"+conversionRateToPound;
	}
	
	
}