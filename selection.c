#include<stdio.h>
void swap(int *p,int *q);
void selectionsort(int a[],int n)
{
	int i,small,j,ind;
	for(i=0;i<n-1;i++)
	{
		small=a[i];
		ind=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<small)
			{
				small=a[j];
				ind=j;
				swap(&a[i],&a[j]);
			}
		}
	}	
}
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}

void read(int a[],int n)
{
	int i;
	printf("Enter the numbers : ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}void print(int a[],int n)
{
	int i;
	printf("Sorted array : ");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}
void main()
{
	int a[100],n;
	printf("Size of the array : ");
	scanf("%d",&n);
	read(a,n);
	selectionsort(a,n);
	print(a,n);
}
