#include<stdio.h>
int Bi_search(int [],int ,int ,int);
int main()
{
	int n,num,s;
	printf("\n Enter Size: ");
	scanf("%d",&n);
	int arr[n],i;
	printf("\n Enter array: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n Enter a Number to be searched: ");
	scanf("%d",&num);
	s=Bi_search(arr,0,n-1,num);
	if (s!=-1)
	{
		printf("\n Found at position %d",s);
	}
	else
	{
		printf("\n Not Found");
	}
	return 0;
}
int Bi_search(int arr[],int lb,int ub,int num)
{
	
	if (lb<=ub)
	{
		int mid =lb+((ub-lb)/2);
		if (arr[mid]==num)
		 return mid+1;
		else if (arr[mid]>num)
		 return Bi_search(arr,lb,mid-1,num);
		else
		 return Bi_search(arr,mid+1,ub,num);
	}
    return -1;
}
/*
OUTPUT:-
 
 Enter Size: 10

 Enter array: 1 2 3 4 5 6 7 8 9 12

 Enter a Number to be searched: 12

 Found at position 10
--------------------------------

 Enter Size: 10

 Enter array: 1 2 3 4 5 6 7 8 9 12

 Enter a Number to be searched: 11

 Not Found
*/
