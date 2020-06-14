#include<stdio.h>

void Selection_sort(int [],int);
void display(int [],int );

int main()
{
	int n;
	printf("\n Enter size of an array: ");
	scanf("%d",&n);
	int arr[n],i;
	printf("\n Enter Array Element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n Array Before Sort: ");
	display(arr,n);
	printf("\n");
	Selection_sort(arr,n);
	printf("\n Array After Sort: ");
	display(arr,n);
	return 0;
}
void Selection_sort(int arr[],int n)
{
   int i, j, min_idx, temp; 
   for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        {
        	if (arr[j] < arr[min_idx]) 
            min_idx = j;
		}
		temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
   } 
}
void display(int arr[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf (" %d",arr[i]);
	}
}

/* 
OUTPUT:- 
 Enter size of an array: 10

 Enter Array Element: 5 2 11 88 12 0 1 3 89 20

 Array Before Sort:  5 2 11 88 12 0 1 3 89 20

 Array After Sort:  0 1 2 3 5 11 12 20 88 89
 */
