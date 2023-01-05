#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *left;
	struct Node *right;
};
typedef struct Node node;
node *root, *curr, *par=NULL;
node *p;
node *newnode(int r)
{
	p=(node *)malloc(sizeof(node));
	p->info=r;
	p->left=p->right=NULL;
	return p;
}
void Insert_val(int val)
{
	p=newnode(val);
	curr=root;
	while (curr!=NULL)
	{
		par=curr;
		if (val<curr->info)
			curr=curr->left;
		else
			curr=curr->right;
	}
	if (par==NULL)
		root=p;
	else
	{
		if (val<par->info)
			par->left=p;
		else
			par->right=p;
	}
}
void display(node *a)
{
	if(a!=NULL)
	{
		display(a->left);
		printf("%d  ",a->info);
		display(a->right);
	}
}
int Search_node(node *r, int val)
{
	if(r==NULL)
		return(0);
	else
	{
		if (r->info==val)
			return(1);
		else
		{
			if (val<r->info)
				Search_node(r->left,val);
			else
				Search_node(r->right,val);
		}
	}
}
void Delete_node(int ele)
{
	node *stree, *insucc, *Pinsucc;
	par=NULL;
	curr=root;
	while (curr!=NULL && curr->info!=ele)
	{
		par=curr;
		if(ele>curr->info)
			curr=curr->right;
		else
			curr=curr->left;
	}
	if (curr==NULL)
		printf("No such node");
	else
	{
		if(curr->left==NULL || curr->right==NULL)
		{
			if (curr->left==NULL)
				stree=curr->right;
			else
				stree=curr->left;
			if(curr==root)
				root=stree;
			else
			{
				if(curr==par->right)
					par->right=stree;
				else
					par->left=stree;
			}
		}
		else
		{
			Pinsucc=curr;
			insucc=curr->right;
			while (insucc->left!=NULL)
			{
				Pinsucc=insucc;
				insucc=insucc->left;
			}
			curr->info=insucc->info;
			if(Pinsucc==curr)
				Pinsucc->right=insucc->right;
			else
				Pinsucc->left=insucc->right;
		}
		free(curr);
	}
}
void main()
{
	int elem, ch;
	do
	{
		printf("\n1.Insert value\n2.Search node\n3.Delete node\n4.Display\n5.Exit\n");
		printf("\nEnter Your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				printf("Enter the element to be inserted: ");
				scanf("%d",&elem);
				Insert_val(elem);
				break;
			case 2:
				printf("Enter the element to be searched: ");
				scanf("%d",&elem);
				int p=Search_node(root,elem);
				if(p==0)
					printf("\nElement not found.");
				else
					printf("\nElement found.");
				break;
			case 3: 
				printf("Enter the element to be deleted: ");
				scanf("%d",&elem);
				Delete_node(elem);
				break;
			case 4: 
				printf("Elements in Tree are: ");
				display(root);
				break;
			case 5: 
				break;
			default: printf("INVALID");
		}
	} while (ch!=5);
}


