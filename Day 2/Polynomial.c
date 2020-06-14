#include<stdio.h>
 struct poly
 {
	 int coeff;
	 int expo;
 };
 
 struct poly p1[10],p2[10],p3[10];
 int readPoly(struct poly []);
 void displayPoly( struct poly [],int terms);

 int main()
 {
	int t1;
	t1=readPoly(p1);
	printf(" \n First polynomial : ");
	displayPoly(p1,t1);
	return 0;
 }

 int readPoly(struct poly p[10])
 {
	int t1,i;

	printf("\n\n Enter the total number of terms in the polynomial:");
	scanf("%d",&t1);

	printf("\n Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(i=0;i<t1;i++)
	{
		printf("   Enter the Coefficient(%d): ",i+1);
		scanf("%d",&p[i].coeff);
		printf("      Enter the exponent(%d): ",i+1);
		scanf("%d",&p[i].expo);        
	}
	return(t1);
 }

 void displayPoly(struct poly p[10],int term)
 {
	int k;

	for(k=0;k<term-1;k++)
	{
		if (p[k].coeff == 1)
		{
			if (p[k].expo == 0)
				printf("%d + ",1);
			else if (p[k].expo == 1)
				printf("x");
			else 
				printf("(x^%d) + ",p[k].expo);
		}
		else if (p[k].coeff != 0)
		{
			if (p[k].expo == 0)
				printf("%d + ",p[k].coeff);
			else if (p[k].expo == 1)
				printf("%dx + ",p[k].coeff);
			else
				printf("%d(x^%d) + ",p[k].coeff,p[k].expo);
		}	
	}
	if (p[k].coeff == 1)
		{
			if (p[k].expo == 0)
				printf("%d  ",1);
			else if (p[k].expo == 1)
				printf("x");
			else 
				printf("(x^%d)  ",p[k].expo);
		}
		else if (p[k].coeff != 0)
		{
			if (p[k].expo == 0)
				printf("%d  ",p[k].coeff);
			else if (p[k].expo == 1)
				printf("%dx  ",p[k].coeff);
			else
				printf("%d(x^%d)  ",p[k].coeff,p[k].expo);
		}	
	
}
/* OUTPUT:-

 Enter the total number of terms in the polynomial:3

 Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER
   Enter the Coefficient(1): 2
      Enter the exponent(1): 2
   Enter the Coefficient(2): 3
      Enter the exponent(2): 1
   Enter the Coefficient(3): 5
      Enter the exponent(3): 0

 First polynomial : 2(x^2) + 3x + 5
 -----------------------------------------------------------
 */
