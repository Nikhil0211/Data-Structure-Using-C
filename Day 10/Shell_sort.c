#include<stdio.h>

int shellSort(int [], int ); 
void display (int [], int ); 
int main() 
{ 
	int n;
	printf("\n Enter Size of an array: ");
	scanf("%d",&n);
	int arr[n],i;
	printf("\n Enter Array Element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Array before sorting: ") ; 
	display(arr, n); 
	shellSort(arr, n); 
	printf("\nArray after sorting: "); 
	display(arr, n); 
	return 0; 
} 
int shellSort(int arr[], int n) 
{ 
	int gap,i,temp,j;
	for (gap = n/2; gap > 0; gap /= 2) 
	{ 
		for (i = gap; i < n; i += 1) 
		{ 
			temp = arr[i]; 			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap]; 
			arr[j] = temp; 
		} 
	} 
	return 0; 
} 
void display(int arr[], int n) 
{ 
	int i;
	for (i=0; i<n; i++) 
		printf(" %d",arr[i]); 
} 
/* 
OUTPUT:-

 Enter Size of an array: 5

 Enter Array Element: 55 21 1 0 2
Array before sorting:  55 21 1 0 2
Array after sorting:  0 1 2 21 55

*/
