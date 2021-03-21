import java.util.*;
public class ItemNameComp implements Comparator<SItem>
{
   public int compare(SItem it1, SItem it2)
   {
       if((it1.getTitle().compareTo(it2.getTitle())>0))
	      return 1;
    	else 
	      return -1;
	}
}	