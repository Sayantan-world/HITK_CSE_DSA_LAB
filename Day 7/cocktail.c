#include <stdio.h>
int c=0;
int d=0;
void swap(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}

void CocktailSort(int a[], int n)
{
        int swapped = 1;
        int start = 0;
        int end = n - 1;

        while (swapped) {
                // reset the swapped flag on entering
                // the loop, because it might be true from
                // a previous iteration.
                swapped = 0;

                // loop from left to right same as
                // the bubble sort
                for (int i = start; i < end; i++,c++) {
                        if (a[i] > a[i + 1]) {
                                swap(&a[i], &a[i + 1]);
                                swapped = 1;
                        }
                }

                // if nothing moved, then array is sorted.
                if (!swapped)
                        break;

                // otherwise, reset the swapped flag so that it
                // can be used in the next stage
                swapped = 0;

                // move the end point back by one, because
                // item at the end is in its rightful spot
                end--;

                // from right to left, doing the
                // same comparison as in the previous stage
                for (int i = end - 1; i >= start; i--,d++) {
                        if (a[i] > a[i + 1]) {
                                swap(&a[i], &a[i + 1]);
                                swapped = 1;
                        }
                }

                // increase the starting point, because
                // the last stage would have moved the next
                // smallest number to its rightful spot.
                ++start;
                if(c>d) {d=c;}
                else{c=d;}
        }
}

void main()
{
        int size,i;
        printf("Enter size of array: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter array: ");
        for (i = 0; i < size; i++)
        {
                scanf("%d", &arr[i]);
        }
        CocktailSort(arr,size);
        for (i = 0; i < size; i++)
        {
                printf("%d ", arr[i]);
        }
        printf("\nCount: %d\n",c);
}
