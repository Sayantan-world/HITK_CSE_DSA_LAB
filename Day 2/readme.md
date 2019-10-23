![Question](https://github.com/Sayantan-world/HITK_CSE_DSA_LAB/blob/master/Day%202/DSLab2.png?raw=true)
---

## Solution 1
---
View the code in d2p1.c

### Output
---
```
Enter the no. of polynomials: 4

Enter the no. of terms:3
Enter the coefficient and exponent:2 3
Enter the coefficient and exponent:3 4
Enter the coefficient and exponent:4 5

Polynomial 1 is:4x^5+3x^4+2x^3

Enter the no. of terms:2
Enter the coefficient and exponent:2 5
Enter the coefficient and exponent:3 4

Polynomial 2 is:3x^4+2x^5

Enter the no. of terms:4
Enter the coefficient and exponent:1 134
Enter the coefficient and exponent:2 6
Enter the coefficient and exponent:3 5
Enter the coefficient and exponent:65 3

Polynomial 3 is:65x^3+3x^5+2x^6+1x^134

Enter the no. of terms:2
Enter the coefficient and exponent:2 4
Enter the coefficient and exponent:3 5

Polynomial 4 is:3x^5+2x^4

The added polynomial is: +67x^3+8x^4+12x^5+1x^134+2x^6

```
---
## Solution 2
---
View the code in d2p2.c

### Output
---
```
Enter the dimensions of matrix: 6 6

Enter elements: 15 0 0 22 0 -15 0 11 3 0 0 0 0 0 0 -6 0 0 0 0 0 0 0 0 91 0 0 0 0 0 0 0 28 0 0 0

Matrix is:

  15 0 0 22 0 -15
  0 11 3 0 0 0
  0 0 0 -6 0 0
  0 0 0 0 0 0
  91 0 0 0 0 0
  0 0 28 0 0 0
  
Triple format is advantageous.

Sparse matrix is:

  6 6 8
  1 1 15
  1 4 22
  1 6 -15
  2 2 11
  2 3 3
  3 4 -6
  5 1 91
  6 3 28
  
Transposed sparse matrix is:

  6 6 8
  1 1 15
  1 5 91
  2 2 11
  3 2 3
  3 6 28
  4 1 22
  4 3 -6
  6 1 -15
  
```
---
## Solution 3
---
View the code in d2p3.c

### Output
---
```
Enter elements:1 2 0 0 0 3 9 0 0 1 4 0

Matrix is:

  1 2 0 0
  0 3 9 0
  0 1 4 0
  
A : 1 2 3 9 1 4
IA : 0 2 4 6
JA : 0 1 1 2 1 2

 ```
