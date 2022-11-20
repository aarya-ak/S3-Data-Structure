#include<stdio.h>
void simplemerge(int a[],int f,int s,int t)
{
	int i,j,k,b[100],n;
	i=f;
	j=s;
	k=0;
	while((i<s) && (j<=t))
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	
	while(i<s)
	{
		b[k++]=a[i++];
	}
	while(j<=t)
	{
		b[k++]=a[j++];
	}
	for(i=f,k=0;i<=t;)
	{
		a[i++]=b[k++];
	}
}
void msort(int a[],int l, int r)
{
	int m;
	
	if(l<r)
	{
		m=(l+r)/2;
		msort(a,l,m);
		msort(a,m+1,r);
		simplemerge(a,l,m+1,r);
	}
}
void readnum(int arr[],int n)
{
	int i;
	printf("Enter the %d numbers* : ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
}
void print (int arr[],int n)
{
	int i;
	printf("Sorted array : ");
	for(i=0;i<n;i++)
		
		printf(" %d ",arr[i]);
}
void main()
{
	int a[100],n;
	printf("Size of the array ***: ");
	scanf("%d",&n);
	readnum(a,n);
	
	msort(a,0,n-1);
	print(a,n);
}	
