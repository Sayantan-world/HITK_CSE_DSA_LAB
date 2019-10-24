
#include <stdio.h>
void swap(int *a, int *b)
{
        int t = *a;
        *a = *b;
        *b = t;
}
void heapify(int arr[], int n, int i)
{
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && arr[l] > arr[largest])
                largest = l;
        if (r < n && arr[r] > arr[largest])
                largest = r;
        if (largest != i)
        {
                swap(&arr[i], &arr[largest]);
                heapify(arr, n, largest);
        }
}
void heapSort(int arr[], int n)
{
        int i;
        for (i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);
        for (i=n-1; i>=0; i--)
        {
                swap(&arr[0], &arr[i]);
                heapify(arr, i, 0);
        }
}
void main()
{
        int size,i;
        printf("Enter size of array: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter array\n");
        for (i = 0; i < size; i++)
                scanf("%d", &arr[i]);
        heapSort(arr, size);
        printf("The sorted array is : ");
        for (i = 0; i < size; i++)
                printf("%d ", arr[i]);
        printf("\n");
}
