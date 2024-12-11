#include<stdio.h>
int main()
{
	int i,n,sum=0;
	printf("Enter the no of elements:");
	scanf("%d",&n);
	printf("The sum of n numbers:");
	for(i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("%d",sum);
	return(0);
}
