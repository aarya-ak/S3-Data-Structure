#include<stdio.h>
#include<stdlib.h>
#define size 25
struct NODE
{
	int info;
	struct NODE *link;
};
typedef struct NODE node;
node *rear=NULL;
node *front=NULL;
node *newnode(int elem)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->info=elem;
	p->link=NULL;
	return p;
}
void Insertqueue(int elem)
{
	node *p;
	p=newnode(elem);
	p->info=elem;
	p->link=NULL;
	if(front==NULL)
		front=rear=p;
	else
	{
		rear->link=p;
		rear=p;
	}
}
void Deletequeue()
{
	node *val;
	val=front;
	if(val==NULL)
		printf("Queueis empty ");
	else
	{
		val=front;
		front=front->link;
		free(val);
	}
}
void Display()
{
	node *curr;
	curr=front;
	while(curr!=NULL)
	{
		printf("%d ",curr->info);
		curr=curr->link;
		while(curr!=NULL)
			break;
	}
}	
void main()
{
	int ch,value;
	do
	{
		printf("\n1. Insert\n2. Delete\n3. DISPLAY\n4. EXIT\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Value to be inserted ");
				scanf("%d",&value);
				Insertqueue(value);
				break;
			}
			case 2:
			{
				Deletequeue();
				break;
			}
			case 3:
			{
				Display();
				break;
			}
			case 4:
				break;
			default :
				printf("Invalid choice ");
		}
	}
	while(ch!=4);
}

