#include<stdio.h>
#include<stdlib.h>
struct node
{
int val;
struct node* left;
struct node* right;	
};
struct node *root=NULL;
struct node* create(int val)
{
		struct node* pt;
		pt=(struct node*)malloc(sizeof(struct node));
		pt->left=NULL;
		pt->right=NULL;
		pt->val=val;
		return pt;
}
void insert(struct node* pt,int val)
{
	
	if(root==NULL)
	root=create(val);
	else
	{
		if(val<pt->val)
		{
		if(pt->left==NULL)pt->left=create(val);		
		else insert(pt->left,val);
		}
		else
		{
		if(pt->right==NULL)pt->right=create(val);
		else insert(pt->right,val);
		}
	}
	
}
void inorder(struct node* root)
{
	if(root==NULL)
	return;
	
	else
	{inorder(root->left);
	printf("\t%d,",root->val);
	inorder(root->right);
	}
}
void preorder(struct node* root)
{
	if(root==NULL)
	return;
	
	else
	{
	printf("\t%d,",root->val);
	preorder(root->left);
	preorder(root->right);
	}
}
int height(struct node* root)
{
	if(root==NULL)
	return 0;
	else
	{
		if(height(root->left)>=height(root->right))
		return height(root->left)+1;
		else return height(root->right)+1;
	}

}
void postorder(struct node* root)
{
	if(root==NULL)
	return;
	
	else
	{postorder(root->left);
	postorder(root->right);
	printf("\t%d,",root->val);
	}
}
void delete(struct node* root,int val)
{
	struct node* x,y;
	if(root==NULL)printf("\n tree is empty");
	
	while(root!=NULL)
	{
		if(root->val==val)
		{
			x=root->left;
			if(root->left==NULL&&root->right==NULL)
		while(root->left)
		{
			
		}
		}
			
}
int main()
{
	int ch,val;
	do
	{
		printf("\n 1) Insert\n 2)Inorder \n 3)Preorder \n 4)Postorder\n 5)Height \n 6)Delete \n 7) Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter value you want to enter");
					scanf("%d",&val);
					insert(root,val);
			break;
			case 2: inorder(root);break;
			case 3: preorder(root);break;
			case 4: postorder(root);break;
			case 5: printf("%d",height(root));break;
			case 7:break;
			default: printf("\n Invalid Entry");
				
		}
	
	}while(ch!=7);
return 0;
}
