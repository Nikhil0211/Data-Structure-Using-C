#include<stdio.h>
int binary_search(int *,int ,int);
int main()
{
	int n,i,num,pos;
	printf("\n Enter size of an array: ");
	scanf("%d",&n);
	int arr[n];
	printf ("\n Enter array element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf ("\n Enter a number to be searched: ");
	scanf("%d",&num);
	pos=binary_search(arr,n,num);
	if (pos==-1)
	{
		printf("\n Not Found \n");
	}
	else
	{
		printf("\n Found at %d",pos+1);
	}
	return 0;
}
int binary_search(int *arr,int n,int num)
{
	int i,mid,lw,up;
	lw=0;
	up=n-1;
	
	while(lw<=up)
	{
		mid=lw+((up-lw)/2);
		if (arr[mid]==num)
		{
			return mid;
		}
		else if (arr[mid]<num)
		{
			lw=mid+1;
		}
		else
		{
			up=mid-1;
		}
	}
	return -1;
}
/* OUTPUT:-

TEST CASE 1:-

 Enter size of an array: 5

 Enter array element: 1 2 3 4 5

 Enter a number to be searched: 3

 Found at 3
------------------------------------
TEST CASE 2:-

 Enter size of an array: 5

 Enter array element: 1 2 3 4 5

 Enter a number to be searched: 6

 Not Found

*/
