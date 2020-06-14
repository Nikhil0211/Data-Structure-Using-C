#include<stdio.h>

void merge_sort(int [],int ,int );
void merge(int [],int ,int);
void display(int [],int );

int main()
{
	int n;
	printf("\n Enter size of an array: ");
	scanf("%d",&n);
	int arr[n],i;
	printf("\nEnter Array: ");
	for (i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf ("\n Array Before sort: ");
	display(arr,n);
	merge_sort(arr,0,n-1);
	printf ("\n Array After Sort: ");
	display(arr,n);	
return 0;
}

void display(int arr[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf (" %d ",arr[i]);
	}
}

void merge_sort(int arr[],int lb,int ub)
{
	if (lb<ub)
	{
		int mid=lb+((ub-lb)/2);
		merge_sort(arr,lb,mid);
		merge_sort(arr,mid+1,ub);
		merge(arr,lb,ub);
	}
}

void merge(int arr[],int lb,int ub)
{ 
    int i, j, k,m;
    m=(lb+ub)/2;
    int n1 = m - lb + 1; 
    int n2 = ub - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[lb + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0;  
    k = lb; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

/* 
OUTPUT:-

 Enter size of an array: 5

 Enter Array: 0 2 25 1 5

 Array Before sort:  0  2  25  1  5
 Array After Sort:  0  1  2  5  25
 
 */
