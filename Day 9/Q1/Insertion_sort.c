#include<stdio.h>

void insertion_sort(int [],int );
void display(int [],int );

int main()
{
	int n;
	printf("\n Enter Size of an Array: ");
	scanf("%d",&n);
	int arr[n],i;
	printf("\n Enter Array Element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf ("\n Array Before Sort: ");
    display(arr,n);
    printf("\n");
    insertion_sort(arr,n);
	printf("\n Array After Sort: ");
	display(arr,n);
	return 0;
}
void insertion_sort(int arr[],int n)
{
	int i, key, j; 
    for (i = 1; i < n; i++) 
	{ 
     	key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) 
		{ 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
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
 Enter Size of an Array: 10

 Enter Array Element: 5 2 1 8 9 6 55 0 15 -1

 Array Before Sort:  5 2 1 8 9 6 55 0 15 -1

 Array After Sort:  -1 0 1 2 5 6 8 9 15 55
*/
