
public class Item
{
	private int itemId;
	private String title;
	public Item()
	{
		itemId = 0;
		title = " ";
    }		
	
	public Item(int id, String title)
	{
		this.itemId = id;
		this.title= title;
	}	
	
	public int getItemId() {
		return itemId;
	}

	public void setItemId(int itemId) {
		this.itemId = itemId;
	}

	public String getTitle() {
		return this.title;
	}

	public void setTitle(String title) {
		this.title = title;
	}
	public String toString()
	{
		return ""+itemId+" "+title;
	}
}
