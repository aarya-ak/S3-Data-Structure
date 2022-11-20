#include<stdio.h>
#include<stdlib.h>
#define size 5

			
int stack[size];int top=0;
int isfull()
{
	if(top==size)
		return(1);
	else
		return(0);
}
int isempty()
{
	if(top==0)
		return(1);
	else
		return(0);
}
void push(int elem)
{
	if(isfull())
		printf("\nStack is full,cannot push value");
	else
		stack[top++]=elem;
}
int pop()
{
	if(isempty())
		printf("\nStack is empty");
	else
	{
		top=top-1;
		return(stack[top]);
	}
}
int peek()
{
	if(isempty())
		printf("\nStack is empty");
	else
		return(stack[top-1]);
}

int displaystack()
{
	int i;
	for(i=0;i<top;i++)
	{
		printf("%d",stack[i]);
	}
}			
void main()
{
	int ch,elem;
	
	do
	{
		printf("\n 1. Push");
		printf("\n 2. Pop");
		printf("\n 3. Peek");
		printf("\n 4. isfull");
		printf("\n 5. isempty");
		printf("\n 6. display stack");
		printf("\n 7. exit");
		printf("\n Enter your choice");
		scanf("%d",&ch);	
		switch(ch)
		{
			case 1:
			if(! isfull())
			{
				printf("Enter the element to be pushed : ");
				scanf("%d",&elem);
				push(elem);
			}
			break;
			case 2:
			if(! isempty())
			{
				elem=pop();
				printf("Element is %d ",elem);
			}
			break;
			case 3:
			if(! isempty())
			{
				elem=peek();
				printf("\nElement is %d ",elem);
			}
			break;
			case 4:
			if(isfull())
			{
				printf("\nStack is full");
			}
			else 
			{
				printf("\nStack is not full");
			}
			break;
			case 5:
			if( isempty())
			{
				printf("\nStack is empty");
			}
			break;
			case 6:
			{
				displaystack();
			}
			break;
			case 7:
			{
				break;
			}
			default :
				printf("\nInvalid choice, Enter a valid choice");
		}
	
	}
while (ch!=7);
}
