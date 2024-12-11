#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *Llink;
    struct Node *Rlink;
};
struct Node *header = NULL;
struct Node *CreateNode(int data)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->Llink = NULL;
    newnode->Rlink = NULL;
    return newnode;
}
void insert_at_front(int data)
{
    struct Node *newnode;
    newnode = CreateNode(data);

    if (header == NULL)
    {
        header = newnode;
    }
    else
    {    
        newnode->Rlink = header;
        header->Llink = newnode;
        header = newnode;
    }
}
void insert_at_end(int data)
{
    struct Node *ptr;
    struct Node *newnode;
    newnode = CreateNode(data);
    
    if (header == NULL)  
    {
        header = newnode;  
    }
    else
    {
        ptr = header;
        while (ptr->Rlink != NULL) 
        {
            ptr = ptr->Rlink;
        }
        ptr->Rlink = newnode;  
        newnode->Llink = ptr;  
    }
}
void insert_at_any(int key, int data)
{
    struct Node *ptr = header;
    struct Node *newnode;
    
    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->Rlink;
    }

    if (ptr == NULL)
    {
        printf("Key not found, insertion not possible\n");
        return;
    }

    newnode = CreateNode(data);
    newnode->Rlink = ptr->Rlink;
    if (ptr->Rlink != NULL) 
    {
        ptr->Rlink->Llink = newnode;
    }
    ptr->Rlink = newnode;
    newnode->Llink = ptr;
}
void delete_at_front()
{
    struct Node *ptr;
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = header;
        header = header->Rlink;
        if (header != NULL)
        {
            header->Llink = NULL;
        }
        free(ptr);
        printf("Node deleted from the front\n");
    }
}
void delete_at_end()
{
    if (header == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct Node *ptr;
        struct Node *ptr1;
        ptr = header;
        while (ptr->Rlink != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->Rlink;
        }
        ptr1->Rlink = NULL;
        free(ptr);
        printf("Node deleted from the end\n");
    }
}
void delete_At_Any(int key)
{
    if (header == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *ptr = header;
    struct Node *prev = NULL;

    while (ptr != NULL && ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->Rlink;
    }

    if (ptr == NULL)
    {
        printf("Key not found, deletion not possible\n");
        return;
    }

    if (prev == NULL)
    {
        header = ptr->Rlink;
    }
    else
    {
        prev->Rlink = ptr->Rlink;
    }

    if (ptr->Rlink != NULL)
    {
        ptr->Rlink->Llink = prev;  
    }

    free(ptr);
    printf("Node with key %d deleted\n", key);
}
void traversal()
{
    struct Node *ptr = header;
    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Rlink;
    }
    printf("\n");
}
void search(int key)
{
    struct Node *ptr = header;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {    
            printf("Key %d found in the list\n", key);
            return;
        }
        ptr = ptr->Rlink;
    }
    printf("Key %d not found in the list\n", key);
}
int main()
{
    int choice, data, key;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete at any position\n");
        printf("7. Traverse the list\n");
        printf("8. Search a node\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	switch(choice)
        {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insert_at_front(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter key to insert after: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_any(key, data);
                break;
            case 4:
                delete_at_front();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_At_Any(key);
                break;
            case 7:
                traversal();
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 9); 

    return 0;
}
