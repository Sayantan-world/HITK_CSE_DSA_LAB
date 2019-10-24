#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
        while (l <= r)
        {
                int m = l + (r-l)/2;
                if (arr[m] == x)
                        return m;
                if (arr[m] < x)
                        l = m + 1;
                else
                        r = m - 1;
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
