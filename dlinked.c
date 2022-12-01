#include<stdio.h>
#include<stdlib.h>
#define size 25
struct NODE
{
	struct NODE *prev;
	int info;
	struct NODE *next;
};
typedef struct NODE node;
node *head=NULL;
node *tail=NULL;
node *newnode(int elem)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->info=elem;
	p->next=NULL;
	return p;
}
void InsertFirst(int elem)
{
	node *p;
	p=newnode(elem);
	p->prev=NULL;
	p->info=elem;
	p->next=head;
	if(head==NULL)
	{
		head=tail=p;
		p->next=NULL;
	}
	else
	{
		head->prev=p;
		head=p;
	}
}
void InsertLast(int elem)
{
	node *p;
	p=newnode(elem);
	p->prev=tail;
	p->info=elem;
	p->next=NULL;
	if(tail==NULL)
		head=tail=p;
	else
	{
		tail->next=p;
		tail=p;
	}
}
void InsertAfter(int elem,int val)
{
	node *curr=head;
	while(curr!=head && curr->info!=val)
		curr=curr->next;
	if(curr==NULL)
		printf("Node not found");
		return;
	node *p;
	p=newnode(elem);
	p->info=elem;
	p->prev=curr;
	p->next=curr->next;
	if(curr->next=NULL)
		tail=p;
	else
		curr->next->prev=p;
	curr->next=p;
	
}
void InsertBefore(int elem,int val)
{
	node *curr=head;
	while(curr!=head && curr->info!=val)
		curr=curr->next;
	if(curr==NULL)
	{
		printf("Node not found");
		return;
	}
	node *p;
	p=newnode(elem);
	p->info=elem;
	p->prev=curr->prev;
	p->next=curr;
	if(curr->prev==NULL)
		head=p;
	else
		curr->prev->next=p;
	curr->prev=p;
}
void Delete(int val)
{
	node *curr=head;
	while(curr!=NULL && curr->info!=val)
		curr=curr->next;
	if(curr==NULL)
	{
		printf("Node not found");
		return;
	}
	else
	{
		if(curr->prev==NULL)
			head=curr->next;
		else
			curr->prev->next=NULL;
			if(curr->next=NULL)
				tail=curr->prev;
			else
				curr->next->prev=curr->prev;
	free(curr);
	}
}
void Display()
{
	node *curr=head;
	while(curr!=NULL)
	{
		printf("%d ",curr->info);
		curr=curr->next;
		
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
				InsertFirst(elem);
				break;
			}
			case 2:
			{
				printf("After which element : ");
				scanf("%d",&x);
				printf("Element to insert : ");
				scanf("%d",&elem);
				InsertAfter(elem,x);
				break;
			}
			case 3:
			{
				printf("Before which element : ");
				scanf("%d",&x);
				printf("Element to insert : ");
				scanf("%d",&elem);
				InsertBefore(elem,x);
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
				
