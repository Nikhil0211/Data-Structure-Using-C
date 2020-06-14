#include <stdio.h>

int sentinalSearch(int [],int ,int );

int main() 
{ 
  	int n;
  	printf("\n Enter size of an array: ");
  	scanf("%d",&n);
  	int arr[n],i,x,pos;
  	printf("\n Enter array element: ");
  	for (i=0;i<n;i++)
  	{
  		scanf("%d",&arr[i]);	
	}
	printf("\n Enter number to be searched: ");
	scanf("%d",&x);
    pos = sentinelSearch(arr, n, x); 
	if (pos == 0)
	{
		printf("\n Not Found");
	}
	else
	{
		printf("\n Found at position %d",pos);
	}
    return 0; 
}   
int sentinelSearch(int arr[], int n, int x) 
{ 
  
    int last = arr[n - 1]; 
  	arr[n - 1] = x; 
    int i = 0; 
    while (arr[i] != x) 
        i++; 
  	arr[n - 1] = last; 
    if ((i < n - 1) || (x == arr[n - 1])) 
        return i+1; 
    else
        return 0; 
}

/* OUTPUT:-

TEST CASE 1:-
 Enter size of an array: 10

 Enter array element: 5 2 6 52 1 -4 7 8 9 10

 Enter number to be searched: -4

 Found at position 6 
------------------------------------------------
TEST CASE 2:-

 Enter size of an array: 5

 Enter array element: 2 3 6 5 1

 Enter number to be searched: 44

 Not Found

*/
