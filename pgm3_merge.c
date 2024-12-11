#include<stdio.h>
int a[30],b[30],d[50],m,n,i,j;
void sort(int c[],int size)
{
	int temp;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(c[i]>c[j])
			{
				temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
}
void merge(int a[],int b[],int size1,int size2)
{
	for(i=0;i<size1;i++)
	{
		d[i]=a[i];
	}
	for(i=0;i<size2;i++)
	{
		d[m+i]=b[i];
	}
}
void display(int c[],int size)
{
	for(i=0;i<size;i++)
	{
		printf("%d\n",c[i]);
	}
}
int main()
{
	printf("Enter the no of elements in the 1st array:");
	scanf("%d",&m);
	printf("Enter the elements in the 1st array:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the no of elements in the 2nd array:");
	scanf("%d",&n);
	printf("Enter the elements in the 2nd array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\nUnsorted 1st array:");
	display(a,m);
	printf("\nUnsorted 2nd array:");
	display(b,n);
	sort(a,m);
	sort(b,n);
	printf("\nSorted 1st array:");
	display(a,m);
	printf("\nSorted 2nd array:");
	display(b,n);
	int s=m+n;
	printf("Merged array:");
	merge(a,b,m,n);
	display(d,s);
	sort(d,s);
	printf("Merged and Sorted array:");
	display(d,s);
	return(0);
}

