#include<stdio.h>

int main()
{
	int m,n, i, j, c=0;
	printf("\nEnter the size of matrix (m n): ");
	scanf("%d %d", &m, &n);
	int arr[m][n];
	printf("Enter the elements of matrix: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{		
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0)
				c++;
		}
	}
	printf("The matrix is: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	int sparseMatrix[c][3], k=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]!=0)
			{	
				sparseMatrix[k][0]=i;
				sparseMatrix[k][1]=j;
				sparseMatrix[k++][2]=arr[i][j];
			}
		}
	}
	printf("The matrix can be represented as: \n");
	printf("Row Column Value\n");
	for(i=0;i<c;i++)
	{
		printf("%d\t%d\t%d\n",sparseMatrix[i][0],sparseMatrix[i][1],sparseMatrix[i][2]);
	}
	
	printf("The tranpose of above matrix can be represented as: \n");
	printf("Row Column Value\n");
	for(i=0;i<c;i++)
	{
		printf("%d\t%d\t%d\n",sparseMatrix[i][1],sparseMatrix[i][0],sparseMatrix[i][2]);
	}
	return 0;
}

/* OUTPUT:-

Enter the size of matrix (m n): 4 4
Enter the elements of matrix:
0 0 0 0
1 2 0 0
1 0 0 3
0 0 0 0
The matrix is:
0 0 0 0
1 2 0 0
1 0 0 3
0 0 0 0
The matrix can be represented as:
Row Column Value
1       0       1
1       1       2
2       0       1
2       3       3
The tranpose of above matrix can be represented as:
Row Column Value
0       1       1
1       1       2
0       2       1
3       2       3

*/