#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *link;
};
struct Node *header = NULL;
struct Node *create_Node(int data)
{
	struct Node *newnode;
	newnode = malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->link = NULL;
	return newnode;
}
void insert_at_front(int data)
{
	struct Node *newnode;
	newnode = create_Node(data);
	if (header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
}
void insert_at_end(int data)
{
	struct Node *newnode;
	newnode = create_Node(data);
	if (header==NULL)
	{
		header=newnode;
	}
	else
	{
		struct Node *ptr=header;
		while (ptr->link !=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}
void insert_at_any(int data, int position)
{
	struct Node *newnode=create_Node(data);
	if (position==1)
	{
		newnode->link=header;
		header=newnode;
	}
	else
	{
		struct Node *current=header;
		int i;
		for (i=1; i<position-1 && current != NULL; i++)
		{
			current=current->link;
		}
		if(current==NULL)
		{
			printf("Position out of bounds, Inserting at the end.\n");
			insert_at_end(data);
		}
		else
		{
			newnode->link=current->link;
			current->link=newnode;
		}
	}
}
void delete_at_front()
{
    if(header==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct Node * ptr;
        ptr=header;
        header=header->link;
        printf("Deleted element(at front): %d\n",ptr->data);
        free(ptr);
    }
}
void delete_at_end()
{
    if (header==NULL)
    {
	printf("Linked list is empty\n");
    }
    else
    {
        struct Node *ptr = header;
        struct Node *ptr1;

        while (ptr->link != NULL) // Traverse to the second last node
        {
            ptr1 = ptr;
            ptr = ptr->link;
        }

        printf("Deleted element (at end): %d\n", ptr->data);
        free(ptr);
        ptr1->link = NULL;
    }
}
void delete_at_any(int position)
{
    if (header==NULL)
    {
        printf("Linked list is empty\n");
    }

    else
    {
        struct Node *ptr=header;
        struct Node *ptr1;
	for (int i=1; i<position && ptr !=NULL; i++)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }

        if (ptr==NULL)
        {
            printf("Position %d out of bounds\n", position);
        }
        else
        {
            ptr1->link = ptr->link;
            printf("Deleted element(at any): %d\n", ptr->data);
            free(ptr);
        }
    }
}
int search(int value)
{
	struct Node *temp=header;
	int position=1;
	int found=0;
	while (temp != NULL)
	{
		if (temp->data==value)
		{
			printf("Element %d found at position %d\n", value, position);
			found = 1;
		}
		temp=temp->link;
		position++;
	}
	if (!found)
	{
		printf("Element %d not found in the list.\n", value);
	}

	return found;
}
void traversal()
{
	struct Node *ptr = header;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}
int main()
{
	insert_at_front(10);
	insert_at_front(20);
	insert_at_front(3000);
	insert_at_end(100);
	insert_at_end(200);
	insert_at_end(5000);
	insert_at_any(4000,4);
	insert_at_any(1010,5);
	insert_at_any(8647,6);
	printf("Linked List: ");
	traversal();
	delete_at_front();
	delete_at_end();
	delete_at_any(2);
	search(200);
    	search(1010);
    	search(110);
	return 0;
}
