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
        printf("Matrix is \n ");
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
        if(3*nnz+3 < m*n)
        {
                printf("\nTriple format is advantageous.\n");
                int sparseMatrix[nnz+1][3];
                sparseMatrix[0][0] = m;
                sparseMatrix[0][1] = n;
                sparseMatrix[0][2] = nnz;
                int k = 1;
                for(i=0; i<m; i++)
                {
                        for(j=0; j<n; j++)
                        {
                                if(matrix[i][j]!=0)
                                {
                                        sparseMatrix[k][0] = i;
                                        sparseMatrix[k][1] = j;
                                        sparseMatrix[k][2] = matrix[i][j];
                                        k++;
                                }
                        }
                }
                printf("\nSparse matrix is:\n ");
                for(i=0; i<nnz+1; i++)
                {
                        for(j=0; j<3; j++)
                        {
                                if(j==2 || i==0) printf("%2d ", sparseMatrix[i][j]);
                                else printf("%2d ", sparseMatrix[i][j]+1);
                        }
                        printf("\n");
                }
                int sparseT[nnz+1][3];
                sparseT[0][0]=n;
                sparseT[0][1]=m;
                sparseT[0][2]=nnz;
                k=1;
                for(i=0; i<n; i++)
                {
                        for(j=1; j<=nnz; j++)
                        {
                                if(i==sparseMatrix[j][1])
                                {
                                        sparseT[k][0]=i;
                                        sparseT[k][1]=sparseMatrix[j][0];
                                        sparseT[k][2]=sparseMatrix[j][2];
                                        k++;
                                }
                        }
                }
                printf("\nTransposed sparse matrix is:\n ");
                for(i=0; i<nnz+1; i++)
                {
                        for(j=0; j<3; j++)
                        {
                                if(j==2 || i==0) printf("%2d ", sparseT[i][j]);
                                else printf("%2d ", sparseT[i][j]+1);
                        } printf("\n");
                }
        }
        else
                printf("\nTriple format is not advantageous.");
}
