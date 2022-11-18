#include<stdio.h>
void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
			{
			    temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}
void readnum(int a[],int n)
{
	int i;
	printf("Enter numbers : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void printnum(int a[],int n)
{
	int i;
	printf("Sorted numbers are : \n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
} 
void main()
{
	int x[100],n;
	printf("How many numbers : ");
	scanf("%d",&n);
	readnum(x,n);
	bubble_sort(x,n);
	printnum(x,n);
}
