#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *getNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtBegin(Node **head, int data)
{
    Node *newNode = getNode(data);
    if (!*head)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    if (!*head)
    {
        insertAtBegin(head, data);
        return;
    }

    Node *newnode = getNode(data);
    Node *curr;
    for (curr = *head; curr->next; curr = curr->next)
        ;
    curr->next = newnode;
}

void insertAt(Node **head, int data, int pos)
{
    if (pos <= 0)
    {
        insertAtBegin(head, data);
        return;
    }
    Node *newnode = getNode(data);
    Node *temp = *head;
    for (int i = 1; i < pos && temp->next; ++i, temp = temp->next)
        ;
    newnode->next = temp->next;
    temp->next = newnode;
}

void reverse(Node **head)
{
    if (!*head || !(*head)->next)
        return;

    Node *prev = NULL;
    Node *curr = *head;
    Node *next = (*head)->next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void reverseDisplay(Node *head)
{
    Node *lastVisited = NULL;
    while (lastVisited != head)
    {
        Node *curr;
        for (curr = head; curr->next != lastVisited; curr = curr->next)
            ;
        printf("%d ", curr->data);
        lastVisited = curr;
    }
    printf("\n");
}

void sort(Node *head)
{
    for (Node *i = head; i->next; i = i->next)
    {
        Node *min = i;
        for (Node *j = i->next; j; j = j->next)
        {
            if (j->data < min->data)
            {
                min = j;
            }
        }
        if (min != i)
        {
            i->data ^= min->data;
            min->data ^= i->data;
            i->data ^= min->data;
        }
    }
}

int search(Node *head, int key)
{
    int i = 0;
    while (head)
    {
        if (head->data == key)
            return i;
        head = head->next;
        i++;
    }
    return -1;
}

void delete(Node **head, int key)
{
    Node *toDelete;
    // Delete at Beginning
    if (*head && (*head)->data == key)
    {
        toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return;
    }

    Node *curr = *head;
    while (curr && curr->next && curr->next->data != key)
    {
        curr = curr->next;
    }

    // If the key was not found
    if (!curr || !curr->next)
    {
        return;
    }

    toDelete = curr->next;
    curr->next = curr->next->next;
    free(toDelete);
}

void display(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Specific Position\n");
    printf("4. Display\n");
    printf("5. Delete\n");
    printf("6. Reverse Display\n");
    printf("7. Reverse the Linked List\n");
    printf("8. Search\n");
    printf("9. Sort(using selection sort)\n");

    int data, pos, key;
    while (1)
    {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtBegin(&head, data);
            break;

        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter the data and position: ");
            scanf("%d %d", &data, &pos);
            insertAt(&head, data, pos);
            break;

        case 4:
            display(head);
            break;
        case 5:
            printf("Enter the key: ");
            scanf("%d", &key);
            delete (&head, key);
            break;

        case 6:
            reverseDisplay(head);
            break;
        case 7:
            reverse(&head);
            break;
        case 8:
            printf("Enter the key: ");
            scanf("%d", &key);
            printf(search(head, key) != -1 ? "Found\n" : "Not Found\n");
            break;
        case 9:
            sort(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
