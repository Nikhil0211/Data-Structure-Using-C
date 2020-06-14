#include<stdio.h>

void display(int [],int);
int getMax(int [],int);
void countSort(int [], int , int );
void radixsort(int [], int );
int main() 
{ 
	int n;
	printf("\n Enter Size of an array: ");
	scanf("%d",&n);
	int arr[n],i;
	printf("\n Enter array element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n Array Before Sort: ");
	display(arr,n);
	radixsort(arr, n); 
	printf("\n Array After Sort: ");
	display(arr, n); 
	return 0; 
} 

int getMax(int arr[], int n) 
{ 
	int mx = arr[0],i; 
	for (i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 
void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; 
	int i, count[10] = {0}; 
 
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 
void radixsort(int arr[], int n) 
{ 
	int m = getMax(arr, n),exp; 
	for (exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 
void display(int arr[], int n) 
{ 
	int i;
	for (i = 0; i < n; i++) 
		printf(" %d",arr[i]);	
} 
/* OUTPUT:-
Enter Size of an array: 5

Enter array element: 2 5 1 0 6

Array Before Sort:  2 5 1 0 6
Array After Sort:  0 1 2 5 6

*/
