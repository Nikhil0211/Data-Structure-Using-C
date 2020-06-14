#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int mid_square(int x, int d)
{
	long int x1;
	int n;
	x1=pow(x,2);
	printf("Square of %d is %d\n",x,x1);
	n=(int)log10(x)+1;
	x1=((int)(x1/(long int)pow(10,n-d)));
	return (x1%(long int)pow(10,d));
}
int folding(int x, int d)
{
	int s=0,n,x1;
	while(x>0)
	{
		n=(int)log10(x)+1;
		x1=(int)(x/pow(10,n-d));
		printf("%d\n",x1);
		s=s+x1;
		x=x%(int)pow(10,n-d);
	}
	printf("--------\nSum is %d\n",s);
	return (s%(int)(pow(10,d)));
}
int main()
{
	int ch,key,d;
	printf("Enter no of digit in hash index\n");
	scanf("%d",&d);
	while(1)
	{
		
		printf("1.Mid-Square Method\n2.Folding Method\n3.Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the key\n");
					scanf("%d",&key);
					printf("Hash index of %d is %d\n",key,mid_square(key,d));
					break;
			case 2: printf("Enter the key\n");
					scanf("%d",&key);
					printf("Hash index of %d is %d\n",key,folding(key,d));
					break;
			case 3: exit(0);
		}
	}
}
/*OUTPUT:-
Enter no of digit in hash index
3
1.Mid-Square Method
2.Folding Method
3.Exit
Enter your choice
1
Enter the key
3271
Square of 3271 is 10699441
Hash index of 3271 is 944
1.Mid-Square Method
2.Folding Method
3.Exit
Enter your choice
2
Enter the key
139427829
139
427
829
--------
Sum is 1395
Hash index of 139427829 is 395
1.Mid-Square Method
2.Folding Method
3.Exit
Enter your choice
3

*/

