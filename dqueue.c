#include<stdio.h>
#define size 25
int Q[size],rear=-1,front=-1;
int isempty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if((front==rear+1)||((front==0)&&(rear==size-1)))
		return 1;
	else
		return 0;
}
void Insertrear(int elem)
{
	if(isfull())
		printf("Queue is Full");
	else
	{
		if(front==-1)
			front=rear=0;
		else
			rear=(rear+1)%size;
		Q[rear]=elem;
	}
}
int Deletefront()
{
	int val=-1;
	if(isempty())
	{
		printf("Queue is empty");
	}
	else
	{
		val=front;
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%size;
	}
	return val;
}
void Display()
{
	if(isempty())
		printf("Queue is empy");
	else
	{
		int i;
		printf("Queue : ");
		for(i=front;i!=rear;i=(i+1)%size)
		{
			printf("%d",Q[i]);
		}
		printf("%d",Q[rear]);
	}
}
void Insertfront(int elem)
{
	if(isfull())
		printf("Queue is full");
	else
	{
		if(isempty())
			front=rear=0;
		else
			front=(front+size-1)%size;
		Q[front]=elem;
	}
}
int Deleterear()
{
	int val=-1;
	if(isempty())
		printf("Queue is empty");
	else
		val=rear;
	if(front==rear)
		front=rear=-1;
	else
		rear=(rear+size-1)%size;
	return val;
}
int main()
{
	int ch,freq;
	
	do{
		printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				int elem;
				printf("Element to be inserted : ");
				scanf("%d",&elem);
				printf("Insert to 1. rear 2. front ");
				scanf("%d",&freq);
				if(freq==1)
					Insertrear(elem);
				else if(freq==2)
					Insertfront(elem);
				else
					printf("Invalid");
				break;
			case 2:
			{
				int val;
				printf("Delete from 1. front 2. rea");
				scanf("%d",&freq);
				if(freq==1)
					val=Deletefront();
				else if(freq==2)
					 val=Deleterear();
				else
					printf("Invalid");
				if(val!=-1)
					printf("Deleted element is%d", Q[val]);
					break;
				case 3:Display();
				break;
				case 4: break;
				}
			}
		}
	}
	while(ch!=4);
	printf("Invalid choice");
}





	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
