#include<stdio.h>
int binarysearch(int a[],int n,int elem)
{
	int top=0,bot=n-1,mid;
	while(top<=bot)
	{
		mid=(top+bot)/2;
		if(a[mid]==elem)
			return (mid+1);
		else if(elem<a[mid])
			bot=mid-1;
		else
			top=mid+1;
	}
	return (-1);
}

void read(int a[],int n)
{
	int i;
	printf("Enter the elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void main()
{
	int a[100],n,e,p;
	printf("Enter the numbers : ");
	scanf("%d",&n);
	read(a,n);
	printf("Element to be searched : ");
	scanf("%d",&e);
	p=binarysearch(a,n,e);
	if(p==-1)
		printf("Element not present");
	else 
		printf("Element present at : %d",p);
}

