#include<stdio.h>
void swap(int *,int *);
int partition (int [], int , int );
void quickSort(int [], int , int );
void display(int [],int);
int main()
{
	int n;
	printf ("\nEnter Size of an Array: ");
	scanf ("%d",&n);
	int arr[n],i;
	printf("\n Enter Array Element: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf ("\n Array Before Sort: ");
    display(arr,n);
    printf("\n");
	quickSort(arr, 0, n-1);
	printf("\n Array After Sort: ");
	display(arr,n);

return 0;
}

void display(int arr[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf (" %d",arr[i]);
	}
}
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int j,i = (low - 1);   
    for (j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

/* 
OUTPUT:-
 Enter Size of an Array: 10

 Enter Array Element: 25 15 0 1 2 53 6 8 7 10

 Array Before Sort:  25 15 0 1 2 53 6 8 7 10

 Array After Sort:  0 1 2 6 7 8 10 15 25 53
*/ 
