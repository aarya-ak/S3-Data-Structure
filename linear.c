#include<stdio.h>
int linear_search(int x[],int n, int key)
{
	int i;
	for(i=0;i<n;i++)
		if(x[i]==key)
			return(i+1);
	return 0;
}
void main()
{
	int a[100],n,e,p,i;
	printf("How many numbers : ");
	scanf("%d",&n);
	printf("Enter the numbers : ");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Element to be searched : ");
	scanf("%d",&e);
	p=linear_search(a,n,e);
	if(p==0)
		printf("Element not present\n");
	else 
		printf("Element present at : %d\n ",p);
} 
