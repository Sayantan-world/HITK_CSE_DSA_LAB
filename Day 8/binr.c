#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
        if (r >= l)
        {
                int mid = l + (r - l)/2;
                if (arr[mid] == x) return mid;
                if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
                return binarySearch(arr, mid+1, r, x);
        }
        return -1;
}

int main(void)
{
        int n,i,x;
        printf("\nEnter size of array: ");
        scanf("%d",&n);
        int arr[n];
        printf("\nArray elements: ");
        for (i = 0; i < n; i++)
                scanf("%d",&arr[i]);
        printf("\nEnter the element to be searched: ");
        scanf("%d",&x);
        int result = binarySearch(arr, 0, n-1, x);
        (result == -1) ? printf("Element is not present in array\n")
        : printf("Element is present at index %d\n", result);
        return 0;
}
