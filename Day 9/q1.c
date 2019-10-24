#include <stdio.h>
#include <stdlib.h>
int f=-1,r=-1;
void enque(int q[], int n)
{
        int num;
        printf("Enter the number to be inserted: ");
        scanf("%d",&num);
        if(f==0 && r==n || f==r+1) printf("Overflow");
        else if(f==-1 && r==-1)
        {
                r=f=0;
                q[r]=num;
        }
        else if(r==n && f!=0)
        {
                r=0;
                q[r]=num;
        }
        else
        {
                r++;
                q[r]=num;
        }
}
int deque(int q[], int n)
{
        int item;
        if(f==-1 && r==-1)
        {
                printf("Underflow");
                return -1;
        }
        else
        {
                item=q[f];
                if(f==r) f=r=-1;
                else if(f==n) f=0;
                else f++;
        }
        return item;
}
void display(int q[], int n)
{
        if(f==-1) printf("Queue is empty");
        else
        {
                int i;
                if(f<=r)
                {
                        for(i=f; i<=r; i++) printf("%d->",q[i]);
                }
                else
                {
                        for(i=f; i<=n; i++) printf("%d->",q[i]);
                        for(i =0; i<=r; i++) printf("%d",q[i]);
                }
        }
}
void main()
{
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int q[n];
        int val, ch, z=1;
        printf("\n1.Enque\n");
        printf("2.Deque\n");
        printf("3.Display\n");
        while(z!=0)
        {
                printf("Enter choice: ");
                scanf("%d", &ch);
                switch(ch)
                {
                case 1: enque(q, n-1);
                        break;
                case 2: val=deque(q, n-1);
                        if(val!=-1)
                        {
                                printf("Value deleted from the stack is %d",val);
                        }
                        break;
                case 3: display(q, n-1);
                        break;
                default: printf("Wrong option\n");
                }
                printf("Do you want to continue? Press 0 to exit\n");
                scanf("%d", &z);
        }
}
