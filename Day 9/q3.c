#include <stdio.h>
#include <stdlib.h>
struct Node {
        int data;
        struct Node* next;
};
struct queue {
        struct Node *front, *rear;
};
struct Node* newNode(int k)
{
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = k;
        newnode->next = NULL;
        return newnode;
}
struct queue* createQueue()
{
        struct queue* q = (struct queue*)malloc(sizeof(struct queue));
        q->front = q->rear = NULL;
        return q;
}
void RenQueue(struct queue* q, int k)
{
        struct Node* newnode = newNode(k);
        if (q->front==NULL) {
                q->front = q->rear = newnode;
                q->rear->next=q->rear;
                return;
        }
        q->rear->next = newnode;
        q->rear = newnode;
        q->rear->next=q->front;
}
void LenQueue(struct queue* q, int k)
{
        struct Node* newnode = newNode(k);
        if (q->front==NULL) {
                q->front = q->rear = newnode;
                q->rear->next=q->rear;
                return;
        }
        newnode->next=q->front;
        q->front=newnode;
        q->rear->next=q->front;
}
int LdeQueue(struct queue* q)
{
        struct Node *ptr;
        int value;
        if (q->front == NULL)
        {
                printf("Underflow");
                return -1;
        }
        if(q->front==q->rear)
        {
                value=q->front->data;
                free(q->front);
                q->front=q->rear=NULL;
        }
        else
        {
                ptr=q->front;
                value=ptr->data;
                q->front=q->front->next;
                q->rear->next=q->front;
                free(ptr);
        }
        return value;
}
int RdeQueue(struct queue* q)
{
        struct Node *ptr,*preptr;
        int value;
        preptr=q->front;
        if (q->front == NULL)
        {
                printf("Underflow");
                return -1;
        }
        if(q->front==q->rear)
        {
                value=q->rear->data;
                free(q->rear);
                q->front=q->rear=NULL;
        }
        else
        {
                ptr=q->rear;
                value=ptr->data;
                while(preptr->next!=ptr) preptr=preptr->next;
                free(ptr);
                q->rear=preptr;
                preptr->next=q->front;
        }
        return value;
}
void display(struct queue *q)
{
        struct Node *ptr;
        ptr=q->front;
        if(q->front==NULL)
        {
                printf("empty");
                return;
        }
        while(ptr->next!=q->front)
        {
                printf("%d ",ptr->data);
                ptr=ptr->next;
        }
        printf("%d ",ptr->data);
}
void ird()
{
        struct queue* q = createQueue();
        int ch,n,val, z=1;
        printf("\n 1.Insert at right");
        printf("\n 2.Delete from left");
        printf("\n 3.Delete from right");
        printf("\n 4.Display");
        while(z!=0)
        {
                printf("\n Enter your option:");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1: printf("Enter the data:");
                        scanf("%d",&val);
                        RenQueue(q,val);
                        break;
                case 2: n = LdeQueue(q);
                        if (n!=-1)
                                printf("Dequeued item is %d", n);
                        break;
                case 3: n = RdeQueue(q);
                        if (n!=-1)
                                printf("Dequeued item is %d", n);
                        break;
                case 4: display(q);
                        break;
                default: printf("Wrong option\n");
                }
                printf("Do you want to continue? Press 0 to exit\n");
                scanf("%d", &z);
        }
}
void ord()
{
        struct queue* q = createQueue();
        int ch,n,val, z=1;
        printf("\n 1.Delete at left");
        printf("\n 2.Insert from left");
        printf("\n 3.Insert from right");
        printf("\n 4.Display");
        while(z!=0)
        {
                printf("enter your option:");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1: n = LdeQueue(q);
                        if (n!=-1)
                                printf("Dequeued item is %d", n);
                        break;
                case 2: printf("Enter the data:");
                        scanf("%d",&val);
                        LenQueue(q,val);
                        break;
                case 3: printf("Enter the data:");
                        scanf("%d",&val);
                        RenQueue(q,val);
                        break;
                case 4: display(q);
                        break;
                default: printf("Wrong option\n");
                }
                printf("Do you want to continue? Press 0 to exit\n");
                scanf("%d", &z);
        }
}
void main()
{
        int ch, z=1;
        printf("\n1.Input restricted");
        printf("\n2.Output restricted");
        while(z!=0)
        {
                printf("\nEnter your option: \n");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1: ird();
                        break;
                case 2: ord();
                        break;
                default: printf("Wrong option");
                }
        }
}
