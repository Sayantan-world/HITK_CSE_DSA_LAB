/*
   Day 3: Singly Linked List

   1. Write a menu driven program to implement a singly linked list with the operations:
   i) create the list
   ii) insert any element in any given position (front, end or intermediate)
   iii) delete an element from any given position (front, end or intermediate)
   iv) display the list
   v) count the number of nodes
   vi) reverse the list

 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
        int data;
        struct node * next;
};
struct node * start = NULL;
struct node * create(struct node *);
struct node * insert_front(struct node *);
struct node * insert_end(struct node *);
struct node * insert_inter(struct node *);
struct node * del_front(struct node *);
struct node * del_end(struct node *);
struct node * del_inter(struct node *);
struct node * display(struct node *);
struct node * count(struct node *);
struct node * reverse(struct node *);

int main()
{
        int ch;
        do
        {
                printf("\n1.Create the list");
                printf("\n2.Display the list");
                printf("\n3.Insert an element at beg");
                printf("\n4.Insert an element at end");
                printf("\n5.Insert an element at intermediate");
                printf("\n6.Delete an element from beg");
                printf("\n7.Delete an element from end");
                printf("\n8.Delete an element from intermediate");
                printf("\n9.Count the No. of nodes");
                printf("\n10.Reverse the list");
                printf("\n11.Exit");
                printf("\nEnter Your Choice - ");
                scanf("%d",&ch);
                switch(ch)
                {
                case 1: start=create(start);
                        break;
                case 2: start=display(start); printf("\n");
                        break;
                case 3: start=insert_front(start);
                        break;
                case 4: start=insert_end(start);
                        break;
                case 5: start=insert_inter(start);
                        break;
                case 6: start=del_front(start);
                        break;
                case 7: start=del_end(start);
                        break;
                case 8: start=del_inter(start);
                        break;
                case 9: start=count(start);
                        break;
                case 10: start=reverse(start);
                        break;
                case 11: exit(1);
                        break;
                default: printf("\nWrong Choice!!");
                }
        } while(ch!=11);
        return 0;
}
struct node * create(struct node * start)
{
        struct node * new_node,*ptr;
        int num;
        printf("\nEnter -1 to end");
        printf("\nEnter the data - ");
        scanf("%d",&num);
        while(num!=-1)
        {
                new_node=(struct node * )malloc(sizeof(struct node));
                new_node->data = num;
                if(start==NULL)
                {
                        new_node->next=NULL;
                        start = new_node;
                }
                else
                {
                        ptr = start;
                        while(ptr->next!=NULL)
                                ptr=ptr->next;
                        ptr->next=new_node;
                        new_node->next=NULL;
                }
                printf("\nEnter the data - ");
                scanf("%d",&num);
        }
        return start;
}
struct node * display(struct node * start)
{
        struct node *  ptr;
        ptr=start;
        if(ptr==NULL)
                printf("\nNo data!!");
        else{
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->data);
                        ptr=ptr->next;
                }
        }
        return start;

}
struct node * insert_front(struct node * start)
{
        int num;
        struct node * new_node;
        new_node=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data - ");
        scanf("%d",&num);
        new_node->data=num;
        new_node->next = start;
        start=new_node;
        return start;
}
struct node * insert_end(struct node * start)
{
        int num;
        struct node * new_node,*ptr;
        ptr=start;
        new_node=(struct node *)malloc(sizeof(struct node ));
        printf("\nEnter the element  - ");
        scanf("%d",&num);
        new_node->data=num;
        new_node->next=NULL;
        while(ptr->next!=NULL)
                ptr=ptr->next;
        ptr->next=new_node;

        return start;
}
struct node * insert_inter(struct node * start)
{
        int num,val;
        struct node * new_node,*ptr,*preptr;
        ptr=start;
        new_node=(struct node *)malloc(sizeof(struct node ));
        printf("\nEnter the element  - ");
        scanf("%d",&num);
        new_node->data=num;
        printf("\nEnter the value before which the data has to be inserted  - ");
        scanf("%d",&val);
        ptr=start;
        while(ptr->data!=val)
        {
                preptr=ptr;
                ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->next=ptr;
        return start;
}
struct node * del_front(struct node * start)
{
        struct node * ptr;
        ptr=start;
        start=start->next;
        free (ptr);
        return start;
}
struct node * del_end(struct node *start)
{
        struct node *ptr,*preptr;
        ptr=start;
        while(ptr->next!=NULL)
        {
                preptr=ptr;
                ptr=ptr->next;
        }
        preptr->next=NULL;
        free(ptr);
        return start;
}
struct node * del_inter(struct node *start)
{
        struct node *ptr,*preptr;
        int val;
        printf("\nEnter the value which the data has to be deleted  - ");
        scanf("%d",&val);
        ptr=start;
        while(ptr->data!=val)
        {
                preptr=ptr;
                ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;

}
struct node * count(struct node * start)
{
        struct node *ptr;
        int c=0;
        ptr=start;
        while(ptr!=NULL)
        {
                c++;
                ptr=ptr->next;
        }
        printf("\nTotal number of nodes - %d",c);
        return start;
}
struct node * reverse(struct node * start)
{
        struct node * ptr,*preptr,*temp;
        ptr=start;
        preptr=NULL;
        while(ptr!=NULL)
        {
                temp=ptr->next;
                ptr->next=preptr;
                preptr=ptr;
                ptr=temp;
        }
        start=preptr;
        return start;
}
