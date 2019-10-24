#include <stdio.h>
#include <stdlib.h>
//Doubly linked list
struct List {    //Done
        int data;
        struct List *next;
        struct List *prev;
};
typedef struct List *node;

node create()   //Done
{
        node temp;
        temp = (node)malloc(sizeof(struct List));
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
}

node addListEnd(node head, int val) //Done
{
        node temp,p;
        temp = create();
        temp->data = val;
        if(head == NULL)
        {
                head = temp;
        }
        else
        {
                p = head;
                while(p->next != NULL)
                        p = p->next;

                temp->prev = p;
                p->next = temp;
        }
        return head;
}

void print(node head)   //Done
{
        node temp;

        temp = head;
        printf("\nList: ");
        while(temp != NULL)
        {
                printf("%d ",temp->data);
                temp= temp->next;
        }
        printf("\n");
}

node addListStart(node head, int val)   //Done
{
        node temp;
        temp = create();

        temp->data = val;

        temp->next = head;
        head->prev = temp;
        head = temp;

        return head;

}

node add(node head, int val, int pos)   //Done
{
        node temp, ptr;
        int i;
        temp = create();
        ptr  = head;
        temp->data = val;

        if(pos==1)
        {
                head = addListStart(head, val);
                return head;
        }
        else
        {
                for(i=2; i<=pos-1; i++)
                {
                        ptr = ptr->next;
                }

                if(ptr->next != NULL)
                {
                        temp->next = ptr->next;
                        ptr->next->prev = temp;
                        temp->prev = ptr;
                        ptr->next = temp;
                }
                else
                {
                        ptr->next = temp;
                        temp->prev = ptr;
                }
                return head;
        }

}

node del(node head, int pos)    //Done
{
        node ptr;
        int i;
        ptr = head;

        if(head==NULL)
        {
                printf("List empty!\n");
                return head;
        }

        if(pos == 1)
        {
                head->next->prev = NULL;
                head = head->next;
                free(ptr);
        }
        else
        {
                for(i=2; i<=pos-1; i++)
                {
                        ptr = ptr->next;
                }

                if(ptr->next->next != NULL)
                {
                        ptr->next = ptr->next->next;
                        free(ptr->next->prev);
                        ptr->next->prev = ptr;
                }
                else
                {
                        free(ptr->next);
                        ptr->next = NULL;
                }
        }
        return head;
}

node Rev(node head)
{
        node temp, last, ptr;
        if(head==NULL) {
                printf("\nList is empty\n");
                return head;
        }

        last = head;
        while(last->next != NULL)
        {
                last = last->next;
        }

        ptr = head;
        while(ptr != NULL)
        {
                temp = ptr->next;
                ptr->next = ptr->prev;
                ptr->prev = temp;
                ptr = temp;
        }
        temp = head;
        head = last;
        last = temp;
        return head;
}

int main()
{
        int n,p,v,pos, ans=1, choice;
        node head = NULL;

        printf("Enter number of elements: \n");
        scanf("%d",&n);
        p=n;
        while(p)
        {
                printf("\nEnter data: ");
                scanf("%d",&v);
                head = addListEnd(head,v);
                p--;
        }
        printf("\n");
        print(head);

        do
        {
                printf("\nEnter your choice:\n 1. Add at any position\n 2. Delete at any position\n 3. Add n elements at the end\n 4. Add n elements at the beginning\n 5. Reverse List\nYour choice: ");
                scanf("%d", &choice);
                switch(choice)
                {
                case 1: printf("\nEnter the position and element: ");
                        scanf("%d%d", &pos, &v );
                        if(pos<=n+1) {
                                head = add(head, v, pos);
                                print(head);
                                n++;
                        }
                        else{
                                printf("\nYou cant break my code :P\n");
                        }
                        break;

                case 2: printf("\nEnter the position to delete: ");
                        scanf("%d", &pos);
                        if(pos==1 && n==1)
                        {
                                printf("\nUnderflow\n");
                                head=NULL;
                                break;
                        }
                        else if(pos<=n) {
                                head = del(head, pos);
                                print(head);
                                n--;
                        }
                        else{
                                printf("\nYou cant break my code :P\n");
                        }
                        break;

                case 3: printf("\nEnter number of elements at the End: \n");
                        scanf("%d",&n);
                        while(n)
                        {
                                printf("\nEnter data: ");
                                scanf("%d",&v);
                                head = addListEnd(head,v);
                                n--;
                        }
                        printf("\n");
                        print(head);
                        break;

                case 4: printf("\nEnter number of elements at Start: \n");
                        scanf("%d",&n);
                        while(n)
                        {
                                printf("\nEnter data: ");
                                scanf("%d",&v);
                                head = addListStart(head,v);
                                n--;
                        }
                        printf("\n");
                        print(head);
                        break;

                case 5: printf("\nReverse of the List is: \n");
                        //Rev(head);
                        head = Rev(head);
                        printf("\n");
                        print(head);
                        break;

                default: printf("\nInvalid choice! \n");
                }

                printf("\nContinue (0-1)? ");
                scanf("%d", &ans);

        } while(ans!=0);
        free(head);
        return 0;
}
