#include <stdio.h>
int Adjmat[4][4] = {
    {0, 0, 1, 0},  
    {1, 0, 0, 0},  
    {0, 0, 0, 1}, 
    {0, 1, 0, 0}   
};
int visit[4] = {0, 0, 0, 0};
int queue[4];
int front = -1;
int rear = -1;
int isEmpty() 
{
	return front == -1;
}
int isFull() 
{
	return rear == 4 - 1;
}
void enqueue(int element)
{
	if (isFull()) 
	{
        	printf("Queue is full\n");
        	return;
    	}
    	if (isEmpty()) 
	{
        	front = rear = 0;
    	}
	else
	{
        	rear++;
    	}
    	queue[rear] = element;
}
int dequeue() 
{
	if (isEmpty()) 
	{
        	printf("Queue is empty\n");
        	return -1;
    	}
    	int element = queue[front];
    	if (front == rear) 
	{
        	front = rear = -1;
    	}
	else 
	{
        	front++;
    	}
    	return element;
}
void bfs(int startNode) 
{
	enqueue(startNode);
    	visit[startNode] = 1;
    	printf("BFS Traversal: ");
	while (!isEmpty()) 
	{
        	int currentNode = dequeue();
        	printf("%d ", currentNode + 1);
		for (int i=0;i<4;i++) 
		{
            		if (Adjmat[currentNode][i] == 1 && visit[i] == 0) 
			{
                		enqueue(i);
                		visit[i] = 1;
            		}
        	}
    	}
    	printf("\n");
}
int main() 
{
	bfs(0); 
    	return 0;
}
