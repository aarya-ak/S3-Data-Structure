#include<stdio.h>
void insertionsort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		
			while(j>=0 && a[j]>key)
			{
				a[j+1]=a[j];
				j--;
			}
		
		a[j+1]=key;
	}
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
	insertionsort(a,n);
	print(a,n);
}
