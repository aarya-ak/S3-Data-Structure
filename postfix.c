#include<stdio.h>
#define size 5
char stack[size];
int top=0;
char isfull()
{
	if(top==size)
		return(1);
	else
		return(0);
}
char isempty()
{
	if(top==0)
		return(1);
	else
		return(0);
}
char push(char c)
{
	if(isfull())
		printf("\nStack is full,cannot push value");
	else
	stack[top++]=c;
}
char pop()
{
	if(isempty())
		printf("\nStack is empty");
	else
	{
		top=top-1;
		return(stack[top]);
	}
}
char peek()
{
	if(isempty())
		printf("\nStack is empty");
	else
		return(stack[top-1]);
}

int intprio(char ch)
{
	switch (ch)
	{
		case'+':
		case'-':
			return 1;
		case'*':
		case'/':
			return  3;
		case'^':
			return 6;
	}
}
int intstack(char ch)
{
	switch (ch)
	{
		case'+':
		case'-':
			return 2;
		case'*':
		case'/':
			return 4;
		case'^':
			return 5;
		case'(' :
			return 0;
	}
}
int main()
{
	char in[50],post[50],c,token;
	int j=0;
	printf("Enter the infix expression : ");
	scanf("%[^\n]",in);
	for(int i=0;in[i]!='\0';i++)
	{
		switch(token=in[i])
		{
			case'(':
				push(in[i]);
				break;
			case'*':
			case'/':
			case'+':
			case'-':
			case'^':
				while(!isempty() && intstack(peek())>intprio(in[i]))
				{
					post[j++]=pop();
				}
				push(token);
				break;
			case')':
				if((c=pop())!='(');
					
					post[j++]=c;
				break;
			default:post[j++]=token;
		}
	}
	while(!isempty())
	{
		post[j++]=pop();
	}
	post[j++]='\0';
	printf("Postfix expresion :%s",post);
}
	
	
	
	
	
	
	
			
			
			
			
			
			
			
