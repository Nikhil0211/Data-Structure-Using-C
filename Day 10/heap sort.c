#include<stdio.h>
#define N 20

void heapsort(int a[],int);
void maxheap(int [],int);

main()
{
	int a[N],n,i,j;
	printf("How many elements do you want to enter= ");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Original Array\n");
	for(j=0;j<n;j++)
		printf("%d ",a[j]);
	heapsort(a,n);
	printf("\n\nThe sorted array\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
void maxheap(int a[],int n)
{
	int i,c,p,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		c=i;
		p=(c-1)/2;
		while(c>0 && temp>a[p])
		{
			a[c]=a[p];
			c=p;
			p=(c-1)/2;
		}
		a[c]=temp;
	}
}
void heapsort(int a[],int n)
{
	int p=n,temp,i;
	while(p>=2)
	{
		maxheap(a,p);
		temp=a[0];
		a[0]=a[p-1];
		a[p-1]=temp;
		printf("\nPass %d\n",n-p);
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		p--;
	}
}

/* output

How many elements do you want to enter= 5
Enter the elements
54
43
12
2
23
Original Array
54 43 12 2 23
Pass 0
23 43 12 2 54
Pass 1
2 23 12 43 54
Pass 2
12 2 23 43 54
Pass 3
2 12 23 43 54

The sorted array
2 12 23 43 54

*/
