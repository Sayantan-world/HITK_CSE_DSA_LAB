/*
   Question :

   2. Write a program (WAP) to check whether a matrix is i) identity, ii) diagonal.

   AUTHOR : SAYANTAN PAL
   DATE : 15.07.2019

 */

 #include <stdio.h>
 #include <stdlib.h>

int main(){


        int r1,c1,flag=1;
        printf("\nEnter the number of rows and col of matrix 1: ");
        scanf("%d%d",&r1,&c1);

        int **m1;

        m1 = (int **)malloc(r1 * sizeof(int *));

        int i,j;

        for (i=0; i<r1; i++) {
                m1[i]=(int *)malloc(c1 * sizeof(int));
        }

        printf("\nEnter the elements in the matrix: \n");
        /*Input in the matrices*/
        for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                        scanf("%d",&m1[i][j] );
                }
        }

        /*Calculations.............*/
        for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                        if(i!=j) {
                                if(m1[i][j]!=0) {
                                        printf("\nNot a diagonal matrix :(\n");
                                        return 0;
                                }
                        }
                        if(i==j) {
                                if(m1[i][j]) {
                                        if(m1[i][j]!=1) {
                                                flag=0;
                                                continue;
                                        }
                                }
                                else{
                                        printf("\nNot a diagonal matrix :(\n");
                                        return 0;
                                }
                        }
                }
        }

        /*Printing......*/
        if(flag == 1) printf("\nIts an identity matrix :)\n");
        else printf("\nIts a diagonal matrix\n");

}
