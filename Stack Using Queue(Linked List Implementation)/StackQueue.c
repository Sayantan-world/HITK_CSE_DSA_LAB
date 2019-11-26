//Author- Akashdeep Das

#include <stdio.h>
#include <stdlib.h>
struct Q
{
    int data;
    struct Q* next;
};
typedef struct Q* Queue;

struct stack
{
    Queue q1;
    Queue q2;
};
typedef struct stack *Stack;

Queue create()
{
    Queue temp = malloc(sizeof(struct Q));
    temp->next = NULL;
    return temp;
}

Queue enqueue(Queue head, int val)
{
    Queue temp = create();
    temp->data = val;

    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        Queue ptr = head;
        while(ptr->next!= NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
    return head;
}

Queue dequeue(Queue head)
{
    if(head==NULL)
        printf("Underflow\n");
    else
    {
        Queue temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

int peek(Queue head)
{
    if(head==NULL)
        printf("Underflow\n");
    else
    {
        return head->data;
    }
}

int countNodes(Queue head)
{
    int count=0;
    Queue ptr = head;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

Stack push(Stack S, int val)
{
    S->q1 = enqueue(S->q1, val);
    return S;
}

Stack pop(Stack S)
{
    while(countNodes(S->q1)!=1)
    {
        S->q2 = enqueue(S->q2, peek(S->q1));
        S->q1 = dequeue(S->q1);
    }

    printf("\nPopped: %d", peek(S->q1));
    S->q1 = dequeue(S->q1);

    Queue temp;
    temp = S->q1;
    S->q1 = S->q2;
    S->q2 = temp;

    return S;

}

void display(Stack S)
{
    Queue ptr;
    ptr = S->q1;
    printf("\n");
    while(ptr!=NULL)
    {
         printf("%d ", ptr->data);
         ptr = ptr->next;
    }

    ptr = S->q2;
    printf("\n");
    while(ptr!=NULL)
    {
         printf("%d ", ptr->data);
         ptr = ptr->next;
    }
}
int main()
{
    int n,v, ans=1, choice;
    Stack S = malloc(sizeof(struct stack));

    S->q1 = NULL;
    S->q2 = NULL;

    do
    {
        printf("\nEnter your choice:\n 1. Stack Push\n 2. Stack Pop\n 3. Exit\nYour choice: ");
        scanf("%d", &choice);
        switch(choice)
        {

            case 1: printf("Enter number of values: ");
                    scanf("%d", &n);
                    while(n--)
                    {
                        printf("\nEnter value: ");
                        scanf("%d", &v);
                        S = push(S, v);
                    }
                    display(S);
                    break;

            case 2: printf("Enter number of values: ");
                    scanf("%d", &n);
                    while(n--)
                    {
                        S = pop(S);
                    }
                    display(S);
                    break;

            case 3: return 0;

            default: printf("\nInvalid choice! \n");
        }

        printf("\nContinue (0-1)? ");
        scanf("%d", &ans);

    }while(ans!=0);

    return 0;
}

