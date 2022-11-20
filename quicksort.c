#include<stdio.h>
void swap(int *p,int*q);
int partition(int a[], int left ,int right)
{
	int key=a[left],i=left+1, j=right;
	do
	{
		while(a[i]<key && i<right)
		{
			i++;
		}
		while(a[j]>key && j>left)
		{
			j--;
		}
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
	}
	while(i<j);
	{
		swap(&a[left],&a[j]);
		return j;
	}
}
void quicksort(int a[], int left, int right)
{
	if(left<right)
	{
		int pos = partition(a,left,right);
		quicksort(a,left,pos-1);
		quicksort(a,pos+1,right);
	}
}
void swap(int *p,int*q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
void readnum(int arr[],int n)
{
	int i;
	printf("Enter the numbers : ");
	for(i=0;i<n;i++)
		
		scanf("%d",& arr[i]);
}
void print (int arr[],int n)
{
	int i;
	printf("Sorted array : ");
	for(i=0;i<n;i++)
		
		printf("%d ",arr[i]);
}
void main()
{
	int x[100],n;
	printf("Size of the array : ");
	scanf("%d",&n);
	readnum(x,n);
	quicksort(x,0,n-1);
	print(x,n);
}
