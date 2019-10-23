#include <stdio.h>
void main()
{
        int m, n, i, j, nnz = 0;
        printf("Enter the dimensions of matrix: ");
        scanf("%d%d", &m, &n);
        int matrix[m][n];
        printf("Enter elements:");
        for(i = 0; i<m; i++) {
                for(j = 0; j<n; j++)
                        scanf("%d", &matrix[i][j]);
        }
        printf("\nMatrix is: \n");
        for(i = 0; i<m; i++)
        {
                for(j = 0; j<n; j++)
                {
                        printf("%2d ", matrix[i][j]);
                } printf("\n");
        }
        //Counting nnz
        for(i = 0; i < m; i++)
        {
                for(j = 0; j < n; j++)
                {
                        if(matrix[i][j] != 0) nnz++;
                }
        }
        if(2*nnz+(m+1)>m*n)
        {
                int a[nnz],ia[m+1],ja[nnz];
                ia[0]=0;
                int k=0;
                //insertion in a[] ja[] ia[]
                for(i = 0; i < m; i++)
                {
                        for(j = 0; j < n; j++)
                        {
                                if(matrix[i][j] != 0)
                                {
                                        a[k]=matrix[i][j];
                                        ja[k]=j;
                                        k++;
                                }
                        }
                        ia[i+1]=k;
                }
                //Print a
                printf("\nA :");
                for(i=0; i<nnz; i++) {
                        printf("%2d ",a[i]);
                }
                printf("\n");
                //Print ia
                printf("\nIA :");
                for(i=0; i<m+1; i++) {
                        printf("%2d ",ia[i]);
                }
                printf("\n");
                //Print ja
                printf("\nJA :");
                for(i=0; i<nnz; i++) {
                        printf("%2d ",ja[i]);
                }
                printf("\n");
        }
}
