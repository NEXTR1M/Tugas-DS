#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int x;
    struct tnode *next;
    struct tnode *prev;//4
} *head, *tail, *curr;

void push_front(int value)
{
    struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    
    if (head == NULL)
    {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;//3
    }
    else
    {
        node->next = head;
        head->prev = node;//1
        head = node;
        head->prev = NULL;//2
    }
}

void push_back(int value)
{

    struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;
    
  
    if (head == NULL)
    {
        head = tail = node;
        tail->next = NULL;
        tail->prev = NULL;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = NULL;
    }
}

void push_mid(int value, int searchKey)
{
    //create node
    struct tnode *node = (struct tnode*)malloc(sizeof(struct tnode));
    node->x = value;

	//checking first node
    if (head == NULL)
    {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        struct tnode *curr = head;
        while (curr != NULL)
        {
            if (curr->x == searchKey)
            {
                
                if (curr == tail)
                {
                    push_back(value);
                }
                else
                {
                    node->next = curr->next;
                    node->prev = curr;
                    if (curr->next != NULL)
                    {
                        curr->next->prev = node;
                    }
                    curr->next = node;
                }
                break;
            }
            //pindahin posisi curr jika tdk ketemu
            curr = curr->next;
        }
        if (curr == NULL)
        {
            printf("Data %d is not found\n", searchKey);
        }
    }
}

void printList()
{
    if (head == NULL)
    {
        printf("There is no data\n");
        return;
    }
	//struct tnode *curr = head;
    curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

void del_back()
{
    if (head == NULL)
    {
        printf("There is no data\n");
        //return;
    }
    else
    {
        if (head == tail)
        {
            free(head);
            head = tail = NULL;
        }
        else
        {
            struct tnode *del = tail;
            tail = tail->prev;
            tail->next = NULL;
            free(del);
        }
    }
}

void del_front()
{
    if (head == NULL)
    {
        printf("There is no data\n");
        //return;
    }
    else
    {
        if (head == tail)
        {
            free(head);
            head = tail = NULL;
        }
        else
        {
            struct tnode *del = head;
            head = head->next;
            head->prev = NULL;
            free(del);
        }
    }
}

void del_mid(int searchKey)
{
    if (head == NULL)
    {
        printf("There is no data\n");
        return;
    }

    struct tnode *curr = head;
    while (curr != NULL)
    {
        if (curr->x == searchKey)
        {
            
            if (curr == head && curr == tail)
            {
                free(curr);
                head = tail = NULL;
            }
            // If the node is at the front
            else if (curr == head)
            {
                del_front();
            }
            // If the node is at the back
            else if (curr == tail)
            {
                del_back();
            }
            // If the node is in the middle
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
            return;
        }
        curr = curr->next;
    }
    printf("Data %d not found\n", searchKey);
}



int main()
{
    printf("Linked List Operations\n");

    push_front(76);
    push_front(90);
    push_front(45);
    // 45 90 76
    push_mid(33, 90);
    // 45 90 33 76
    push_back(50);
    // 45 90 33 76 50

    printList(); // Print: 45 90 33 76 50

    del_back();
    printList(); // Print: 45 90 33 76

    del_front();
    printList(); // Print: 90 33 76

    del_mid(33);
    printList(); // Print: 90 76

    return 0;
}

