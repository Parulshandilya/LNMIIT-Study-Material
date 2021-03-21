/**  Java Program to Implement Singly nexted List */
 
import java.util.Scanner;
 
/*****  Class Node  *****/

class Node
{
    int val;
    Node next;
 
    /*  Constructor  */
    public Node()
    {
        next = null;
        val = 0;
    }   
 
    /*  Constructor  */
    public Node(int d,Node n)
    {
        val = d;
        next = n;
    }
    
    /*  Function to set next to next Node  */
    public void setnext(Node n)
    {
        next = n;
    } 
   
    /*  Function to set val to current Node  */
    public void setval(int d)
    {
        val = d;
    }
    
    /*  Function to get next to next node  */
    public Node getnext()
    {
        return next;
    } 
   
    /*  Function to get val from current Node  */
    public int getval()
    {
        return val;
    }
}
 
/***** Class LinkedList *****/
class LinkedList
{
     Node head;
     Node tail ;
     int size ;
 
    /*  Constructor  */
    public LinkedList()
    {
        head = null;
        tail = null;
        size = 0;
    }
    
    /*  Function to check if list is empty  */
    public boolean isEmpty()
    {
        return head == null;
    }
    
    /*  Function to get size of list  */
    public int getSize()
    {
        return size;
    }    
    
    /*  Function to insert an element at begining  */
    public void insertAtBeginning(int val)
    {
        Node nptr = new Node(val, null);    
        size++ ;    
        if(head == null) 
        {
            head = nptr;
            tail = head;
        }
        else 
        {
            nptr.setnext(head);
            head = nptr;
        }
    }
    
    /*  Function to insert an element at tail  */
    public void insertAtEnd(int val)
    {
        Node nptr = new Node(val,null);    
        size++ ;    
        if(head == null) 
        {
            head = nptr;
            tail = head;
        }
        else 
        {
            tail.setnext(nptr);
            tail = nptr;
        }
    }
    
    /*  Function to insert an element at position  */
    public void insertAtPos(int val , int pos)
    {
        Node nptr = new Node(val, null);                
        Node ptr = head;
        pos = pos - 1 ;
        for (int i = 1; i < size; i++) 
        {
            if (i == pos) 
            {
                Node tmp = ptr.getnext() ;
                ptr.setnext(nptr);
                nptr.setnext(tmp);
                break;
            }
            ptr = ptr.getnext();
        }
        size++ ;
    }
    
    /*  Function to delete an element at position  */
    public void deleteAtPos(int pos)
    {        
        if (pos == 1) 
        {
            head = head.getnext();
            size--; 
            return ;
        }
        if (pos == size) 
        {
            Node s = head;
            Node t = head;
            while (s != tail)
            {
                t = s;
                s = s.getnext();
            }
            tail = t;
            tail.setnext(null);
            size --;
            return;
        }
        Node ptr = head;
        pos = pos - 1 ;
        for (int i = 1; i < size - 1; i++) 
        {
            if (i == pos) 
            {
                Node tmp = ptr.getnext();
                tmp = tmp.getnext();
                ptr.setnext(tmp);
                break;
            }
            ptr = ptr.getnext();
        }
        size-- ;
    }    
    
    /*  Function to display elements  */
    public void display()
    {
        System.out.print("\nSingly nexted List = ");
        if (size == 0) 
        {
            System.out.print("empty\n");
            return;
        }    
        if (head.getnext() == null) 
        {
            System.out.println(head.getval() );
            return;
        }
        Node ptr = head;
        System.out.print(head.getval()+ "->");
        ptr = head.getnext();
        while (ptr.getnext() != null)
        {
            System.out.print(ptr.getval()+ "->");
            ptr = ptr.getnext();
        }
        System.out.print(ptr.getval()+ "\n");
    }
}
 
  /******  Class SinglyLinkedList  ******/
public class SinglyLinkedList
{    
    public static void main(String[] args)
    {             
        Scanner scan = new Scanner(System.in);
        /* Creating object of class nextedList */
        LinkedList list = new LinkedList(); 
        System.out.println("Singly Linked List Test\n");          
        char ch;
        /*  Perform list operations  */
        do
        {
            System.out.println("\nSingly Linked List Operations\n");
            System.out.println("1. insert at begining");
            System.out.println("2. insert at end");
            System.out.println("3. insert at position");
            System.out.println("4. delete at position");
            System.out.println("5. check empty");
            System.out.println("6. get size");       
            System.out.println("7. Display List");
            System.out.println("8. Quit");
     
            int choice = scan.nextInt();            
            switch (choice)
            {
            case 1 : 
                System.out.println("Enter integer element to insert");
                list.insertAtBeginning( scan.nextInt() );                     
                break;                          
            case 2 : 
                System.out.println("Enter integer element to insert");
                list.insertAtEnd( scan.nextInt() );                     
                break;                         
            case 3 : 
                System.out.println("Enter integer element to insert");
                int num = scan.nextInt() ;
                System.out.println("Enter position");
                int pos = scan.nextInt() ;
                if (pos <= 1 || pos > list.getSize() )
                    System.out.println("Invalid position\n");
                else
                    list.insertAtPos(num, pos);
                break;                                          
            case 4 : 
                System.out.println("Enter position");
                int p = scan.nextInt() ;
                if (p < 1 || p > list.getSize() )
                    System.out.println("Invalid position\n");
                else
                    list.deleteAtPos(p);
                break;
            case 5 : 
                System.out.println("Empty status = "+ list.isEmpty());
                break;                   
            case 6 : 
                System.out.println("Size = "+ list.getSize() +" \n");
                break;                         
             case 7:   /*  Display List  */ 
                               list.display();break;
             case 8:  System.out.println(" Exit from the Program...");
                         System.exit(1);
             default : 
                System.out.println("Wrong Entry \n ");
                break;   
            }
            
      
        
           System.out.println("\nDo you want to continue (Type y or n) \n");
            ch = scan.next().charAt(0); // will give the first character of entered string                       
        } while (ch == 'Y'|| ch == 'y');               
    }
}
