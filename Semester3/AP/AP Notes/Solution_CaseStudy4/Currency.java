
abstract class Currency
{
	private int noNotes;
	private int noCoins;
	private int valueOfNote;
	private int valueOfCoin;
	
	public Currency()
	{
		noNotes = 0;
		noCoins = 0;
		valueOfNote=0;
		valueOfCoin=0;
    }		
	
	public Currency(int notes, int coins,int vnotes,int vcoins)
	{
		this.noNotes = notes;
		this.noCoins= coins;
		this.valueOfNote = vnotes;
		this.valueOfCoin = vcoins;
	}	
	public double compute()
	{
		double total1,total2;
		total1 = noNotes*valueOfNote;
		total2 = noCoins*valueOfCoin;
		if(total2>=100)
			total2 = total2/100;
		return total1+total2;
	}
	abstract public double convertToRupees(); //Not able to convert  because not clear at this stage(Dollar or Pound)
	public void print()
	{
		System.out.println(this);
	}
	public String toString()
	{
        return "noNotes:"+noNotes+"  No of Coins:"+noCoins+"\nValue of Note:"+valueOfNote+"  Value of Coin:"+valueOfCoin+"\nTotal Value:"+this.compute();		
	
	}
	
	
}
