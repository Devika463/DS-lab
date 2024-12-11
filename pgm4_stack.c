#include<stdio.h>
#define max 5
int stack[5];
int top=-1;
void push();
void pop();
void traversal();
int main()
{
	int choice;
	printf("1.push\n2.pop\n3.traversal\n4.exit");
	do
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traversal();
				break;
			case 4:
				return(0);
			default:
				printf("wrong choice");
				break;
		}
	}
	while(choice!=4);
	return(0);
}
void push()
{
	int element;
	printf("Enter the element:");
	scanf("%d",&element);
	if(top<max-1)
	{
		
		top=top+1;
		stack[top]=element;
	}
	else
	{
		printf("Stack Overflow");
	}
}
void pop()
{
	int element;
	if(top>=0)
	{
		element=stack[top];
		printf("%d deleted",element);
		top--;
	}
	else
	{
		printf("Stack Underflow");
	}
}
void traversal()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
	}
}
