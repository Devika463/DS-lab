#include<stdio.h>
#define max 5
int cqueue[max];
int front=-1;
int rear=-1;
void enqueue();
void dequeue();
void traversal();
int main()
{
	int choice;
	printf("1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit");
	do
	{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
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
void enqueue()
{
	int element;
	printf("Enter the element:");
	scanf("%d",&element);
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		cqueue[rear]=element;
	}
	else
	{
		if(((rear+1)%max)==front)
		{
			printf("Queue overflow\n");
		}
		else
		{
			rear=(rear+1)%max;
			cqueue[rear]=element;	
		
		}
	}
}
void dequeue()
{
	int element;
	if((front==-1)&&(rear==-1))
	{
		printf("Queue underflow\n");
	}
	else
	{
		if(front==rear)
		{
			front=-1,rear=-1;
		}
		else
		{
			printf("Deleted item is %d",cqueue[front]);
			front=(front+1)%max;
		}
	}
}
void traversal()
{
	int i,j;
	if((front==-1)&&(rear==1))
	{
		printf("Queue is underflow\n");
	}
	else
	{
		if(front>rear)
		{
			for(i=front;i<max;i++)
			{
				printf("%d ",cqueue[i]);
			}
			for(j=0;j<=rear;j++)
			{
				printf("%d ",cqueue[j]);
			}
		}
		else
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d ",cqueue[i]);
			}
		}
		printf("\n");
	}
}
