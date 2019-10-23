/*
   Question :

   1.  WAP to add two polynomials using array. Minimize the memory usage as much as you can.

   AUTHOR : SAYANTAN PAL
   DATE : 23.07.2019

 */
#include <stdio.h>
typedef struct {
        int coeff, exp;
}poly;
poly terms[10];
void main()
{
        int i=0,j=0, k, m, numPoly, numTerms;
        printf("Enter the no. of polynomials: ");
        scanf("%d", &numPoly);
        while(numPoly)
        {
                printf("\nEnter the no. of terms:");
                scanf("%d", &numTerms);
                k=0;
                while(numTerms)
                {
                        printf("\nEnter the coefficient and exponent:");
                        scanf("%d%d", &terms[i].coeff, &terms[i].exp);
                        i++; //counts overall term
                        k++; //count of terms for this polynomial only
                        numTerms--;
                }
                j++; //counting the polynomial
                printf("Polynomial %d is:", j);
                for (m=i-1; m>=i-k; m--)
                {
                        if(terms[m].exp!=0)
                                printf("%dx^%d",
                                       terms[m].coeff, terms[m].exp);
                        else printf("%d", terms[m].coeff);
                        if(m>i-k) printf("+");
                }
                printf("\n");
                numPoly--;
        }
        i--; //adjusting count of terms
        for(j=0; j<i; j++)
        {
                for(k=j+1; k<=i; k++)
                {
                        if((terms[j].coeff != 0) && (terms[k].coeff != 0) &&
                           (terms[j].exp ==terms[k].exp))
                        {
                                terms[j].coeff += terms[k].coeff;
                                terms[k].coeff = 0;
                        }
                }
        }
        printf("\nThe added polynomial is: ");
        for(j=0; j<=i; j++)
        {
                if(terms[j].coeff !=0 && terms[j].exp!=0) printf("+%dx^%d",
                                                                 terms[j].coeff, terms[j].exp);
                else if(terms[j].coeff !=0 && terms[j].exp==0) printf("+%d",
                                                                      terms[j].coeff);
        }
}
