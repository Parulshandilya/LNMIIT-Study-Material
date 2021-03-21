import java.util.*;

public class ItemTest
{
   public static void main(String args[])
   {
      List <SItem> ls =  new ArrayList<SItem>();
	  ls.add(new SItem(111, "Printer"));
	  ls.add(new SItem(444, "Mouse"));
	  ls.add(new SItem(222, "Keyboard"));
	  ls.add(new SItem(333, "Pen Drive"));
	  ls.add(new SItem(888, "Hard disk"));
	  
	  /*for(Item t:ls) 
	  {
		   System.out.println(t);
	  }*/
	  // using Iterator
	 // Iterator <Item> it = ls.iterator();
	  /*while(it.hasNext())
	  {
		  Item temp = it.next();
		  System.out.println(temp);
	  }*/
	  System.out.println("Before Sorting");
	  for(int i=0; i< ls.size();i++)
		   System.out.println(ls.get(i));
	  
	  Collections.sort(ls, new ItemNameComp()); 
	  Iterator <SItem> it = ls.iterator();
	  System.out.println("\nAfter Sorting on the basis of Item name in Ascending order");
	  while(it.hasNext())
	  {
		  SItem temp = it.next();
		  System.out.println(temp);
	  }
	  
	  Collections.sort(ls, new ItemIdComp()); 
	  it = ls.iterator();
	  System.out.println("\nAfter Sorting on the basis of Item Id in Ascending order");
	  // To sort in descending order we need to change in the logic of ItemIdComp class
	  while(it.hasNext())
	  {
		  SItem temp = it.next();
		  System.out.println(temp);
	  }
	  
   }
}   
	  