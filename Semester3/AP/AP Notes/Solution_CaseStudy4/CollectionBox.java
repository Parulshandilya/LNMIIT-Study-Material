import java.util.*;


public class CollectionBox 
{
	public static void displayBox(Dollar dl[], Pound pd[], Rupee rp[], int dsize, int psize, int rsize)
	{
		//System.out.println("Dollar Notes Coins Value Note Value Coin");
		for(int i=0;i<dsize;i++)
			dl[i].print();
		//System.out.println("Pound Notes Coins Value Note Value Coin");
		for(int i=0;i<psize;i++)
			pd[i].print();
		//System.out.println("Rupee Notes Coins Value Note Value Coin");
		for(int i=0;i<rsize;i++)
			rp[i].print();
	}
	public static double calcTotalValueBox(Dollar dl[], Pound pd[], Rupee rp[], int dsize, int psize, int rsize)
	{
		double total1=0, total2=0,total3=0;
		for(int i=0;i<dsize;i++)
			total1= total1+dl[i].convertToRupees();
		for(int i=0;i<psize;i++)
			total2= total2+pd[i].convertToRupees();
		for(int i=0;i<rsize;i++)
			total3= total3+rp[i].convertToRupees();
		return total1+total2+total3;
	}	
		
	public static void main(String[] args) 
	{
		Scanner s = new Scanner(System.in);
		Dollar dollar[] = new Dollar[10];
		Pound  pound[] = new Pound[10];
		Rupee  rupee[] = new Rupee[10];
		char c;
		int i=0,j=0,k=0;
		double grandtotal=0;
		int notes,vnote,coins,vcoin,option,inp;
		do
		{
			
			System.out.println("\n Menu Option:\n1.Add in Dollar Box.");
			System.out.println("2.Add in Pound Box.");
			System.out.println("3.Add in Rupee Box.");
			System.out.println("4.Display All Denomintions in Boxes.");
			System.out.println("5.Convert all Box in Rupees.");
			System.out.println("6.Quit Program.");
			option=s.nextInt();
			
			switch(option)
			{
				case 1: 
								
						System.out.print("\nEnter count of Dollar notes: ");
						notes = s.nextInt();
						System.out.print("\nEnter Denomination of notes: ");
						vnote = s.nextInt();
						System.out.print("\nEnter count of Cent coins: ");
						coins = s.nextInt();
						System.out.print("\nEnter Denomination of coins: ");
						vcoin = s.nextInt();
						dollar[i]= new Dollar(notes,coins,vnote,vcoin);
					    i++; break;
				case 2:
						System.out.print("\nEnter count of Pound notes: ");
						notes = s.nextInt();
						System.out.print("\nEnter Denomination of notes: ");
						vnote = s.nextInt();
						System.out.print("\nEnter count of Pence coins: ");
						coins = s.nextInt();
						System.out.print("\nEnter Denomination of coins: ");
						vcoin = s.nextInt();
						pound[j]= new Pound(notes,coins,vnote,vcoin);
					    j++; break;
				case 3:
						System.out.print("\nEnter count of Rupee notes: ");
						notes = s.nextInt();
						System.out.print("\nEnter Denomination of notes: ");
						vnote = s.nextInt();
						System.out.print("\nEnter count of Paise coins: ");
						coins = s.nextInt();
						System.out.print("\nEnter Denomination of coins: ");
						vcoin = s.nextInt();
						rupee[k]= new Rupee(notes,coins,vnote,vcoin);
					    k++; break;
				case 4: CollectionBox.displayBox(dollar,pound,rupee,i,j,k);
				        break;
				case 5: grandtotal=calcTotalValueBox(dollar,pound,rupee,i,j,k);
				        System.out.println("Grand Total Value in Rupees of Collection Box = "+grandtotal);
					    break;
				case 6: System.out.println("Exiting Program");System.exit(0);
				default:System.out.println("!Wrong Input!");
		}	
         		
			System.out.println("Would you like to continue? (Y/N) : ");
			c = s.next().charAt(0);
			
		}while(c=='y' || c=='Y');
	}

}
