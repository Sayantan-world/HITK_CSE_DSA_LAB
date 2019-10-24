#include <stdio.h>
#include <stdlib.h>
struct Node {
        int key;
        struct Node* next;
};
struct queue {
        struct Node *front, *rear;
};
struct Node* newNode(int k)
{
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->key = k;
        newnode->next = NULL;
        return newnode;
}
struct queue* createQueue()
{
        struct queue* q = (struct queue*)malloc(sizeof(struct queue));
        q->front = q->rear = NULL;
        return q;
}
void enQueue(struct queue* q, int k)
{
        struct Node* newnode = newNode(k);
        if (q->front==NULL)
        {
                q->front = q->rear = newnode;
                q->rear->next=q->rear;
                return;
        }
        q->rear->next = newnode;
        q->rear = newnode;
        q->rear->next=q->front;
}
int deQueue(struct queue* q)
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
                value=q->front->key;
                free(q->front);
                q->front=q->rear=NULL;
        }
        else
        {
                ptr=q->front;
                value=ptr->key;
                q->front=q->front->next;
                q->rear->next=q->front;
                free(ptr);
        }
        return value;
}
void display(struct queue *q)
{
        struct Node *temp=q->front;
        while(temp->next!=q->front)
        {
                printf("%d->",temp->key);
                temp=temp->next;
        }
        printf("%d",temp->key);
}
void main()
{
        struct queue* q = createQueue();
        int n,val,ch, z=1;
        printf("1.Enque\n");
        printf("2.Deque\n");
        printf("3.Display\n");
        while(z!=0)
        {
                printf("Enter choice\n");
                scanf("%d", &ch);
                switch(ch)
                {
                case 1: printf("Enter the data:");
                        scanf("%d",&val);
                        enQueue(q,val);
                        break;
                case 2: n = deQueue(q);
                        if (n!=-1)
                                printf("Dequeued item is %d", n);
                        break;
                case 3: if(q!=NULL) display(q);
                        else printf("Empty queue");
                        break;
                default: printf("Wrong option\n");
                }
                printf("Do you want to continue? Press 0 to exit\n");
                scanf("%d", &z);
        }
}
