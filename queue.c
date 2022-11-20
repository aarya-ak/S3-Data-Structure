#include<stdio.h>
#define size 5

			
int queue[size];
int f=-1,r=-1,q;

void insertq(int elem)
{
	if((r==size-1 && f==0) || f==r+1)
		printf("Queue is full\n");
	else
	{
		r=(r+1);
		if(f==-1);
			f=0;
		queue[r]=elem;
	}
}
int deleteq(int elem)
{
	if(f==-1)
		printf("\nQueue is empty\n");
	else 
	{
		elem=queue[f];
		if(f==r)
			f=r=-1;
		else 
			f=(f+1);
	}
	return elem;
}
int display()
{
	int i;
	for(i=0;i<=f;i++)
	{
		printf("%d",queue[i]);
	}
}
void main()
{
	int elem,n,ch=-1;
	printf("\n 1. insert");
	printf("\n 2. delete");
	printf("\n 3.display");
	printf("\n 4.exit");
	
	do{
	printf("\n Enter your choice : ");
	scanf("%d",&ch);
	switch(ch)
		{
		
			case 1:
			if((r==size-1 && f==0) || f==r+1)
			{
				printf("\nQueue is full");
			}
			else
			{
				printf("Enter the element : ");
				scanf("%d",&elem);
				insertq( elem);
			}
			break;
			case 2:
			if(f==-1)
			{
				printf("\nQueue is empty");
			}
			else{
				elem=deleteq(elem);
				printf("Deleted element ");
				printf("%d",elem);
				}
			break;
			case 3:
			{
				display();
			}
			break;
			case 4:
			{
				break;
			}
			default:
				printf("Invalid choice");
			
		}
	
	}
	while(ch!=4);

}

