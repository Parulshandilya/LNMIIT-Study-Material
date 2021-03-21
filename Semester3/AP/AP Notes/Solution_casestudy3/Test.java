import java.util.*;

public class Test 
{
	public static void main(String[] args) 
	{
		Scanner s = new Scanner(System.in);
		Printed print[] = new Printed[10];
		Multimedia multi[] = new Multimedia[10];
		char c;
		int i=0,j=0;
		
		do
		{
			int option;
			System.out.println("\nMenu: \n\n1.Add an Item in Library.\n2.Display Items.");
			option=s.nextInt();
			
			switch(option)
			{
				case 1: System.out.println("\nChoose type of items to be added: \n1. Printed Items\n2. Multimedia Items\nOption : ");
						int inp = s.nextInt();
						int id;
						String title;
						if(inp==1)
						{
								print[i]= new Printed();
								System.out.println("\nEnter the ItemId:");
								id = s.nextInt();
								print[i].setItemId(id);
								System.out.print("\nEnter the Title: ");
								title = s.next();
								print[i].setTitle(title);
								System.out.println("\nEnter the Page No.: ");
								int page = s.nextInt();
								print[i].setNoPages(page);
							    i++;
						}
						else if(inp==2)
						{
								multi[j]= new Multimedia();
								System.out.println("\nEnter the ItemId:");
								id = s.nextInt();
								multi[j].setItemId(id);
								System.out.print("\nEnter the Title: ");
								title = s.next();
								multi[j].setTitle(title);
								System.out.println("\nEnter Length in Minutes: ");
								int length = s.nextInt();
								multi[j].setLength(length);
							    j++;
						}
						else
							System.out.println("!Wrong Input!");
						break;
						
				case 2: System.out.println("\nPrinted Items:");
						for(int k=0;k<i;k++)
                        System.out.println(print[k]);
						System.out.println("\nMultimedia Items: \n");
						for(int k=0;k<j;k++)
							System.out.println(multi[k]);
						break;
						
				default:System.out.println("!Wrong Option Selected!");
						break;
			}
			
			System.out.println("Would you like to continue? (Y/N) : ");
			c = s.next().charAt(0);
			
		}while(c=='y' || c=='Y');
	}

}
