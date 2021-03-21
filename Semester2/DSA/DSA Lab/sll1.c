#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node* next;
};

struct node* create_A_linked_list();
void insert_A_new_node(int,int,struct node*);
int find_A_node(int,struct node*);
void delete_A_node(int,struct node*);
void display(struct node*);
void modify_A_node(int,int,struct node*);

int main()
{
  int ch,index,node_value,current,new,value;
  struct node* head;
  
  do
 {
  printf("Display Menu\n");
  printf("1.Create a linked list\n");
  printf("2.Insert a new node\n");
  printf("3.Find a node\n");
  printf("4.Delete a node\n");
  printf("5.Display list\n");
  printf("6.Modify a node\n");
  printf("7.exit\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  
  switch(ch)
  { 
    case 1:head=create_A_linked_list();
           break;
    case 2:printf("Enter the index and node value\n");
           scanf("%d%d",&index,&node_value);
           insert_A_new_node(index,node_value,head);
           break;
    case 3:printf("Enter value of node\n");
           scanf("%d",&node_value);
           int i=find_A_node(node_value,head);
           printf("%d",i);
           break;
    case 4:printf("Enter the value of node\n");
           scanf("%d",&value);
           int j= find_A_node(value,head);
           printf("%d",j);
           delete_A_node(j,head);
           break;
    case 5:display(head);
           break;
    case 6:printf("Enter current and new node value\n");
           scanf("%d%d",&current,&new);
           modify_A_node(current,new,head);
           break;
    case 7:break;
   }}
   while(ch!=7);
 
}
struct node* create_A_linked_list()
{
	struct node *ptr;	
	ptr =(struct node*) malloc(sizeof(struct node));
	ptr->data=0;
	ptr->next=NULL;
	return ptr;
}
 

void insert_A_new_node(int index, int new_data, struct node* ptr)
{
	int i;
	struct node *newptr;
	if(index<0 || index > (ptr->data))
	{
		printf("Invalid index..!!!\n\n");
		return;
	}

	newptr = (struct node*)malloc(sizeof(struct node *));
	newptr->data = new_data;

	ptr->data = ptr->data+1;
	i=0;
	while(i < index)
	{
		ptr = ptr->next;
		i++;
	}
	
	newptr->next = ptr->next;
	ptr->next = newptr;
}


int find_A_node(int new_data, struct node *ptr)
{
	int i=1;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
		if(ptr->data == new_data)
			return i;
		i++;
	}	
	
	return -1;
}


void delete_A_node(int j,struct node*ptr)
{
	int i=1;
	struct node* temp_ptr;

	ptr->data = ptr->data - 1;
	
	while(i<j)
	{
		ptr=ptr->next;
		i++;
	}
	
	temp_ptr = ptr->next;
	ptr->next = (ptr->next)->next;

	free(temp_ptr);
}

void display(struct node *ptr)
{
	printf("\nList is...\n");
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
		printf("%d ->",ptr->data);
	}
	printf("NULL\n\n");
}

modify_A_node(int current,int new,struct node* ptr)
{
   while(ptr->next!=NULL)
   {  ptr=ptr->next;
      if(ptr->data==current)
      {
        ptr->data=new;
        break;
      }
      
   }
}
   
































































     










           
      










