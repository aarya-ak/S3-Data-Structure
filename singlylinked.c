#include<stdio.h>
#include<stdlib.h>
#define size 25
struct Node
{
	int info;
	struct Node *link;
};
typedef struct Node node;
node *head = NULL;
node *newnode(int elem)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->info=elem;
	p->link=NULL;
	return p;
}
void Display()
{
	node *curr=head;
	while(curr!=NULL)
	{
		printf("%d ",curr->info);
		curr=curr->link;
		
	}
}
void Insertfirst(int elem)
{
	node *p;
	p=newnode(elem);
	p->info=elem;
	if(head==NULL)
	{
		head=p;
		p->link=NULL;
	}
	else
	{
		p->link=head;
		head=p;
	}	
}
void Insertbefore(int item,int elem)
{
	node *curr=head,*prev=NULL,*p;
	if(curr->info==item)
		Insertfirst(elem);
	while(curr!=NULL && curr->info!=item)
	{
		if(((curr->link)->info)==elem)
		{
			p=newnode(elem);
			p->info=elem;
			p->link=curr->link;
			curr->link=p;
			return ;
		}
		else
		{
			curr=curr->link;
		}
	}
	if(curr==NULL)
		printf("Element not found");
	else
	{
		p=newnode(elem);
		p->link=curr;
		if(curr==head)
			head=p;
		else
		prev->link=p;
	}
}
void Insertafter(int val,int elem)
{
	node*curr=head,*p;
	while(curr!=NULL )
	{
		if(curr->info==val)
		{	
			p=newnode(elem);
			p->info=elem;
			p->link=curr->link;
		}
		else
		{
			curr=curr->link;
			
		}
		if(curr==NULL)
			printf("Element not found");
		else
		{
			p=newnode(elem);
			p->link=curr->link;
			curr->link=p;
			break;
		}
	}
}
void InsertLast(int elem)
{
	node *p;
	node *curr;
	p=newnode(elem);
	p->info=elem;
	p->link=NULL;
	if(head==NULL)
		head=p;
	else
	{
		curr=head;
		while(curr->link!=NULL)
			curr=curr->link;
		curr->link;
	}
}
void Delete(int val)
{
	node*curr=head,*prev=NULL,*p;
	while(curr!=NULL && curr->info!=val)
	{
		prev=curr;
		curr=curr->link;
	}
	if(curr==NULL)
		printf("Element not found");
	else
	{
		if(curr==head)
			head=curr->link;
		else
		{
				prev->link=curr->link;
				free(curr);
		}
	}
}
int main()
{
	int ch,elem,x;
	do
	{
		printf("\n1. Insert first\n2. Insert after\n3. Insert before\n4. Insert last\n5. Display\n6. Delete\n7. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Element to be inserted first : ");
				scanf("%d",&elem);
				Insertfirst(elem);
				break;
			}
			case 2:
			{
				printf("After which element : ");
				scanf("%d",&x);
				printf("Element to insert : ");
				scanf("%d",&elem);
				Insertafter(x,elem);
				break;
			}
			case 3:
			{
				printf("Before which element : ");
				scanf("%d",&x);
				printf("Element to insert : ");
				scanf("%d",&elem);
				Insertbefore(x,elem);
				break;
			}
			case 4:
			{
				printf("Element to be inserted last :");
				scanf("%d",&elem);
				InsertLast(elem);
				break;
			}
			case 5:
			{
				Display();
				break;
			}
			case 6:
			{
				printf("Value to be deleted : ");
				scanf("%d",&elem);
				Delete(elem);
				break;
			}
			case 7:
			{
				break;
			}
			default:
				printf("Invalid choice");
		}
	}
	while(ch!=7);
}
			
