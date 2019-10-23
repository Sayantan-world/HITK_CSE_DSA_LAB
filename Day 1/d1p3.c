/*
   Question :

   3. WAP to reverse the elements of an array without using any other variable.

   AUTHOR : SAYANTAN PAL
   DATE : 15.07.2019

 */

 #include <stdio.h>

int main(){


        int n,i;
        printf("\nEnter the number of elements in array: ");
        scanf("%d",&n);

        int a[n];

        for (i = 0; i < n; i++) {
                scanf("%d",&a[i]);
        }

        /* Manupulating the new matrix.... */

        for (i = 0; i < n/2; i++) {
                a[i] += a[n-i-1];
                a[n-i-1] = a[i] - a[n-i-1];
                a[i] -= a[n-i-1];
        }

        printf("\nFinal array : \n");
        for (i = 0; i < n; i++) {
                printf("%4d",a[i]);
        }
        printf("\n");

}
