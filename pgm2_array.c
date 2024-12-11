#include<stdio.h>
int main()
{
	int i,a[10],n,sum=0;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The sum of array elements:");
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	printf("%d",sum);
	return(0);
}
