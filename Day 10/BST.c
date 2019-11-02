/*
Author- Akashdeep Das
Note- Question 1 and 2 merged in code.

1.  Write a program, which creates a binary search tree (BST). Also write the functions to insert, delete (all possible cases) and search elements from a BST.

2.  Write three functions to traverse a given BST in the following orders:
i) in-order, ii) pre-order, iii) post-order. Display the elements while traversing.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

typedef struct Node *node;

node binTreeSearch(node root, int key)
{
    if(root)
    {
        if(root->data>key)
            return binTreeSearch(root->left,key);
        else if(root->data<key)
            return binTreeSearch(root->right,key);
        else
            return root;
    }
    return NULL;
}

node insertBST(node tree, int key)
{

    node ptr, nodeptr, parentptr;
    ptr = (node)malloc(sizeof(struct Node));
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;

    if(tree == NULL)
    {
        tree = ptr;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;

        while(nodeptr != NULL)
        {
            parentptr = nodeptr;

            if(key<nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }

        if(key < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}

node findMin(node tree)
{
    if(tree->left == NULL || tree == NULL)
        return tree;
    else
        return findMin(tree->left);
}

node findMax(node tree)
{
    if(tree->right == NULL || tree == NULL)
        return tree;
    else
        return findMax(tree->right);
}

void inorder(node root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

node deleteBST(node root, int key)
{
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteBST(root->left, key);

    else if (key > root->data)
        root->right = deleteBST(root->right, key);

    else
    {

        if (root->left == NULL)
        {
            node temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node temp = root->left;
            free(root);
            return temp;
        }

        node temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}


int main()
{
    node root=NULL,temp;
    int ch,n,val;
    while(1)
    {
        printf("\nMENU\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of data: ");
                    scanf("%d",&n);
                    while(n--)
                    {
                        printf("\nEnter data: ");
                        scanf("%d", &val);
                        root=insertBST(root,val);
                    }

                    printf("Inorder Traversal:\nStart-> ");
                    inorder(root);

                    printf("End\n");
                    break;

            case 2:if(root)
                    {
                        printf("Which data you want to delete? ");
                        scanf("%d",&n);
                        root=deleteBST(root,n);
                        if(root)
                        {
                            printf("Inorder Traversal:\nStart-> ");
                            inorder(root);
                            printf("End\n");
                        }
                    }
                    else
                        printf("The tree is empty.\n");

                    break;
            case 3: if(root)
                    {
                        printf("Which data you want to search? ");
                        scanf("%d",&n);
                        temp=binTreeSearch(root,n);
                        if(temp!=NULL)
                            printf("The element %d is present in BST.\n",n);
                        else
                            printf("The element %d is not present in BST.\n",n);
                    }
                    else
                        printf("The tree is empty.\n");
                    break;

            case 4:
                    if(root)
                    {
                        printf("Inorder Traversal:\nStart-> ");
                        inorder(root);
                        printf("End\n");
                    }
                    break;
            case 5:
                    if(root)
                    {
                        printf("Preorder Traversal:\nStart-> ");
                        preorder(root);
                        printf("End\n");
                    }
                    break;
            case 6:
                    if(root)
                    {
                        printf("Postorder Traversal:\nStart-> ");
                        postorder(root);
                        printf("End\n");
                    }
                    break;
            case 7: exit(0);

            default: printf("WRONG CHOICE!!\n");
        }
    }
    return 0;
}
