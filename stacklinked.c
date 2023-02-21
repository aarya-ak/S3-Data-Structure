#include<stdio.h>
#include<stdlib.h>
#define size 25
struct NODE
{
	int info;
	struct NODE *link;
};
typedef struct NODE node;
node *top=NULL;
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
	node *curr;
	curr=top;
	while(curr!=NULL)
	{
		printf("%d ",curr->info);
		curr=curr->link;
		while(curr!=NULL)
			break;
	}
}
void Push(int elem)
{
	node *p;
	p=newnode(elem);
	if(p==NULL)
		printf("Stack is full : OVERFLOW");
	else
	{
		p->info=elem;
		p->link=top;
		top=p;
	}
}
void Pop()
{
	node *val;
	val=top;
	if(val==NULL)
		printf("Stack is empty : UNDERFLOW");
	else
	{
		val=top;
		top=top->link;
		free(val);
	}
}
void main()
{
	int ch,value;
	do
	{
		printf("\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Value to be inserted or pushed ");
				scanf("%d",&value);
				Push(value);
				break;
			}
			case 2:
			{
				Pop();
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
		
