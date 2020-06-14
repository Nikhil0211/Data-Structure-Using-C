#include<stdio.h>

int linear_search(int [],int,int);
void display(int [],int );

int main()
{
	int n;
	printf("\n Enter size of an array: ");
	scanf("%d",&n);
	int arr[n],i,pos,num;
	printf("\n Enter array element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf ("\n Enter number to be searched: ");
	scanf("%d",&num);
	pos = linear_search(arr,n,num);
	if (pos == 0)
	{
		printf("\n Not Found");
	}
	else
	{
		printf("\n Found at index %d",pos);
	}
	return 0;
}
int linear_search(int arr[],int n,int num)
{
	int i,pos=0;
	for (i=0;i<n;i++)
	{
		if (arr[i]==num)
		{
			pos = i+1;
			break;
		}
	}
	return pos;
}

/*
OUTPUT:-

	
 Enter size of an array: 5

 Enter array element: 2 5 1 3 6

 Enter number to be searched: 3

 Found at index 4
 --------------------------------
 
 Enter size of an array: 5

 Enter array element: 2 5 1 3 6

 Enter number to be searched: 7

 Not Found

*/
