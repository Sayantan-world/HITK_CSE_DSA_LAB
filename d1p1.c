/*
   Question :

   1.(a)Create three different 10, 000 X 10, 000 matrices matrixOne, matrixTwo and resultMatrix,
   using dynamic memory allocation. Initialize matrixOne and matrixTwo by using rand() or srand() function,
   limit the values from 0 to 9. Multiply matrixOne and matrixTwo into resultMatrix.
   While execution, open another terminal and use top command to see the usage of
   memory by the process. Calculate the time taken for the execution of the program.

   (b) Repeat the same exercise for 100, 000  X 100, 000 matrices.

   AUTHOR : SAYANTAN PAL
   DATE : 15.07.2019

 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>

int main(){

        srand(time(NULL));
        time_t start,end;
        start = clock();

        int r1,c1,r2,c2;
        printf("\nEnter the number of rows and col of matrix 1: ");
        scanf("%d%d",&r1,&c1);
        printf("\nEnter the number of rows and col of matrix 2: ");
        scanf("%d%d",&r2,&c2);

        if (c1!=r2) {
                printf("\nNOT POSSIBLE :(\n");
                return 0;
        }

        int **m1,**m2,**m3;

        m1 = (int **)malloc(r1 * sizeof(int *));
        m2 = (int **)malloc(r2 * sizeof(int *));
        m3 = (int **)malloc(r1 * sizeof(int *));

        int i,j,k;

        for (i=0; i<r1; i++) {
                m1[i]=(int *)malloc(c1 * sizeof(int));
        }
        for (i=0; i<r2; i++) {
                m2[i]=(int *)malloc(c2 * sizeof(int));
        }
        for (i=0; i<r1; i++) {
                m3[i]=(int *)malloc(c2 * sizeof(int));
        }

        /*Random input in the matrices*/
        for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                        m1[i][j] = rand()%10;
                }
        }
        for (i = 0; i < r2; i++) {
                for (j = 0; j < c2; j++) {
                        m2[i][j] = rand()%10;
                }
        }

        /*Matrix Multiplication...*/
        for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                        for (k = 0; k < c1; k++) {
                                m3[i][j] += (m1[i][k]*m2[k][j]);
                        }
                }
        }

        /*Printing......*/
        /*printf("\nRESULT: \n\n");
           for (i = 0; i < r1; i++) {
                for (j = 0; j < c2; j++) {
                        printf("%4d",m3[i][j]);
                }
                printf("\n");
           }*/

        end = clock();
        printf("\nTime taken : %f\n\n",(float)((end-start)*1.0)/CLOCKS_PER_SEC);
}
