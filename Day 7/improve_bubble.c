#include <stdio.h>
int c=0;
void swap(int *xp, int *yp)
{
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
}

void bubbleSort(int arr[], int n)
{
        int i, j;
        int swapped=0;
        for (i = 0; i < n-1; i++)
        {
                swapped = 0;
                for (j = 0; j < n-i-1; j++,c++)
                {
                        if (arr[j] > arr[j+1])
                        {
                                swap(&arr[j], &arr[j+1]);
                                swapped = 1;
                        }
                }

                if (swapped == 0)
                        break;
        }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
        int i;
        for (i=0; i < size; i++)
                printf("%d ", arr[i]);
        printf("\n");
}

// Driver program to test above functions
int main()
{
        int n,i;
        printf("\nEnter size of array: ");
        scanf("%d",&n);
        int arr[n];
        printf("\nArray elements: ");
        for (i = 0; i < n; i++)
                scanf("%d",&arr[i]);
        bubbleSort(arr, n);
        printf("Sorted array: \n");
        printArray(arr, n);
        printf("\nCount: %d\n",c);
        return 0;
}
