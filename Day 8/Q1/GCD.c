#include <stdio.h> 

int gcd(int ,int );
int main() 
{ 
	int a, b;
	printf("\n Enter two Number: ");
	scanf("%d %d",&a,&b); 
	printf("\n GCD of %d and %d is %d ", a, b, gcd(a, b)); 
	return 0; 
} 
int gcd(int a, int b) 
{ 
	if (a == 0) 
	 return b; 
	if (b == 0) 
	 return a; 
	if (a == b) 
     return a; 
	if (a > b) 
		return gcd(a-b, b); 
	return gcd(a, b-a); 
} 
/*
OUTPUT:-

 Enter two Number: 54 98

 GCD of 54 and 98 is 2
 
 */
