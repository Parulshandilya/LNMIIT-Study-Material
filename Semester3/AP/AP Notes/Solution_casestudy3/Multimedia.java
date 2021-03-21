
public class Multimedia extends Item 
{
	private int length;
    private String type;
	static int temp;
	
	public Multimedia()
	{
		length = 0;
		type = " ";
	}
	 
	public Multimedia(String title, int length,String type)
	{
		super(generateId(), title);  // To call super class "Item" Constructor
		this.length= length;
		this.type = type;
	}
	static                  /* to initialize the static variable temp*/
	{
		temp = 11;
	}
	private static int generateId()  /* method to genearate "id" automatically */
	{
		 return temp++;
	}
	public int getLength() 
	{
		return length;
	}

	public void setLength(int length) 
	{
		this.length = length;
	}
	public String toString()  // to override the method toString() of class Object
	{                         // To convert the class instance variable in a string
	    return super.toString()+" "+type+" "+length;
	}
	// To search the printed item on the basis of Item-ID 
	public int search(Multimedia mt[], int id, int size)
	{
		int i;
		for(i=0;i<size;i++)
			 if(mt[i].getItemId() == id)
				 return i;
	    return -1;
	}
	// To search the printed item on the basis of title 
	public int search(Multimedia mt[], String title, int size)
	{
		int i;
		for(i=0;i<size;i++)
			 if(mt[i].getTitle().equals(title))
				 return i;
	    return -1;
	}
	

	
}
