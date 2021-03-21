
public class Printed extends Item 
{
	private int noPages;
	private String type; // type of printed items are book, magazine, journal etc.
	static int temp;
	
	public Printed()
	{
		noPages = 0;
		type = " ";
	}
	public Printed(String title, int pages,String type)
	{
		super(generateId(), title);  // To call super class "Item" Constructor
		noPages = pages;
	}
	static                  /* to initialize the static variable temp*/
	{
		temp = 111;
	}
	private static int generateId()  /* method to genearate "id" automatically */
	{
		 return temp++;
	}
	public int getnoPages() 
	{
		return noPages;
	}

	public void setNoPages(int pages) 
	{
		this.noPages = pages;
	}
	public String toString()  // to override the method toString() of class Object
	{                         // To convert the class instance variable in a string
	    return super.toString()+" "+type+" "+noPages;
	}
	// To search the printed item on the basis of Item-ID 
	public int search(Printed pt[], int id, int size)
	{
		int i;
		for(i=0;i<size;i++)
			 if(super.getItemId() == id)
				 return i;
	    return -1;
	}
	// To search the printed item on the basis of title 
	public int search(Printed pt[], String title, int size)
	{
		int i;
		for(i=0;i<size;i++)
			 if(super.getTitle().equals(title))
				 return i;
	    return -1;
	}
	
}
