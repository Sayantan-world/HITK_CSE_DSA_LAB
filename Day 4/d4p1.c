#include <stdio.h>
#include <stdlib.h>
struct Node {
        int data;
        struct Node* next;
};
struct Node *head = NULL;

struct Node* create(struct Node* head)
{
        struct Node* newNode, *ptr;
        int num;
        printf("Enter -1 to end the list\n");
        printf("Enter the data:");
        scanf("%d",&num);
        while(num!=-1)
        {   newNode=(struct Node*)malloc(sizeof(struct Node));
            newNode->data=num;
            if(head==NULL)
            {
                    head=ptr=newNode;
                    newNode->next=NULL;
            }
            else
            {
                    ptr->next=newNode;
                    ptr=ptr->next;
                    newNode->next=NULL;
            }
            printf("Enter the data:");
            scanf("%d",&num);}
        newNode->next = head;
        printf("List created\n");
        return head;
}

void display(struct Node* head)
{
        struct Node *ptr;
        ptr=head;
        printf("The list is ");
        do
        {
                printf("%d ", ptr->data );
                ptr=ptr->next;
        }
        while(ptr!=head);
        printf("\n");
}

int count(struct Node* head)
{
        struct Node* ptr;
        int c=1;
        ptr=head;
        ptr=ptr->next;
        while(ptr!=head)
        {
                c++;
                ptr=ptr->next;
        }
        return c;
}

struct Node* insertBeg(struct Node *head)
{
        struct Node* newNode, *ptr;
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data to be inserted at beginning: ");
        scanf("%d", &(newNode->data));
        newNode->next=head;
        ptr=head;
        ptr=ptr->next;
        while(ptr->next!=head)
        {
                ptr=ptr->next;
        }
        ptr->next=newNode;
        head=newNode;
        return head;

}

struct Node* insertEnd(struct Node *head)
{
        struct Node* newNode, *ptr;
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data to be inserted at end: ");
        scanf("%d", &(newNode->data));
        newNode->next=head;
        ptr=head;
        ptr=ptr->next;
        while(ptr->next!=head)
        {
                ptr=ptr->next;
        }
        ptr->next=newNode;
        return head;
}

struct Node *insertInter(struct Node *head)
{
        struct Node *newNode,*ptr,*preptr;
        int pos, counter=1, nodes;
        ptr=preptr=head;
        newNode=(struct Node*)malloc(sizeof(struct Node));
        nodes=count(head);
        printf("No. of nodes are %d\n", nodes);
        printf("Enter position at which it is to be inserted: ");
        scanf("%d", &pos);
        if(pos>nodes) printf("Not possible.\n");
        else if(pos==1) head=insertBeg(head);
        else
        {
                printf("Enter data to be inserted: \n");
                scanf("%d",&(newNode->data));
                while(counter<pos)
                {
                        preptr=ptr;
                        ptr=ptr->next;
                        counter++;
                }
                newNode->next=ptr;
                preptr->next=newNode;
        }
        return head;
}

struct Node *deleteBeg(struct Node *head)
{
        struct Node *ptr;
        ptr=head;
        ptr=ptr->next;
        if(ptr==head)
        {
                free(ptr);
                head=NULL;
        }
        else
        {
                while(ptr->next!=head)
                {
                        ptr=ptr->next;
                }
                ptr->next=head->next;
                free(head);
                head=ptr->next;
        }
        return head;
}
struct Node *deleteEnd(struct Node *head)
{
        struct Node *ptr, *preptr;
        preptr=ptr=head;
        ptr=ptr->next;
        if(ptr==head)
        {
                free(ptr);
                head=NULL;
        }
        else
        {
                while(ptr->next!=head)
                {
                        preptr=ptr;
                        ptr=ptr->next;

                }
                preptr->next=head;
                free(ptr);
        }
        return head;
}
struct Node *deleteInter(struct Node *head)
{
        struct Node *ptr,*preptr;
        ptr=preptr=head;
        int pos, counter=1, nodes;
        nodes=count(head);
        printf("No. of nodes are %d\n", nodes);
        printf("Enter position to be deleted: ");
        scanf("%d", &pos);
        if(pos>nodes) printf("Not possible.\n");
        else if(pos==1) head=deleteBeg(head);
        else
        {
                while(counter<pos)
                {
                        preptr=ptr;
                        ptr=ptr->next;
                        counter++;
                }
                preptr->next=ptr->next;
                free(ptr);
        }
        return head;
}
void main()
{
        int ch, z=1;
        printf("Press 1 to create list\n");
        printf("Press 2 to insert at beginning\n");
        printf("Press 3 to insert at end\n");
        printf("Press 4 to insert at specific position\n");
        printf("Press 5 to delete at beginning\n");
        printf("Press 6 to delete at end\n");
        printf("Press 7 to delete at specific position\n");
        printf("Press 8 to display list\n");

        while(z!=0)
        {
                printf("Enter choice\n");
                scanf("%d", &ch);

                switch(ch)
                {
                case 1: head=create(head);
                        break;
                case 2: if(head!=NULL) head=insertBeg(head);
                        else printf("List is empty.\n");
                        break;
                case 3: if(head!=NULL) head=insertEnd(head);
                        else printf("List is empty.\n");
                        break;
                case 4: if(head!=NULL) head=insertInter(head);
                        else printf("List is empty.\n");
                        break;
                case 5: if(head!=NULL) head=deleteBeg(head);
                        else printf("List is empty.\n");
                        break;
                case 6: if(head!=NULL) head=deleteEnd(head);
                        else printf("List is empty.\n");
                        break;
                case 7: if(head!=NULL) head=deleteInter(head);
                        else printf("List is empty.\n");
                        break;
                case 8: if(head!=NULL) display(head);
                        else printf("List is empty.\n");
                        break;
                default: printf("Wrong option\n");
                }
                printf("Do you want to continue? Press 0 to exit\n");
                scanf("%d", &z);
        }
}


/*Output
   Press 1 to create list
   Press 2 to insert at beginning
   Press 3 to insert at end
   Press 4 to insert at specific position
   Press 5 to delete at beginning
   Press 6 to delete at end
   Press 7 to delete at specific position
   Press 8 to display list
   Enter choice
   1
   Enter -1 to end the list:
   Enter the data:1
   Enter the data:2
   Enter the data:3
   Enter the data:-1
   List created
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 1 2 3 Do you want to continue? Press 0 to exit
   1
   Enter choice
   2
   Enter data to be inserted at beginning: 4
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 4 1 2 3 Do you want to continue? Press 0 to exit
   1
   Enter choice
   3
   Enter data to be inserted at end: 5
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 4 1 2 3 5 Do you want to continue? Press 0 to exit
   1
   Enter choice
   4
   No. of nodes are 5
   Enter position at which it is to be inserted: 3
   Enter data to be inserted:
   6
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 4 1 6 2 3 5 Do you want to continue? Press 0 to exit
   1
   Enter choice
   5
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 1 6 2 3 5 Do you want to continue? Press 0 to exit
   1
   Enter choice
   6
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 1 6 2 3 Do you want to continue? Press 0 to exit
   1
   Enter choice
   7
   No. of nodes are 4
   Enter position to be deleted: 4
   Do you want to continue? Press 0 to exit
   1
   Enter choice
   8
   The list is 1 6 2 Do you want to continue? Press 0 to exit
   0
 */
