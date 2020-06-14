#include <stdio.h>
#include <stdlib.h>

int lower_triangular_matrix(int **,int ,int );
int upper_triangualr_matrix(int **,int,int);
int diagonal_matrix(int **,int ,int );
int identity_matrix(int **,int ,int );
int tridiagonal_matrix(int **,int ,int );

int main()
{
	int **matrix;
	int r,c,i,j,low_tri;
	printf("\n Enter no. of row in a matrix: ");
	scanf("%d",&r);
	printf("\n Enter no. of colum in a matrix: ");
	scanf("%d",&c);
	matrix = (int **)malloc(r * sizeof(int *));
	for (i=0;i<r;i++)
	{
		matrix[i] = (int *)malloc(c * sizeof(int));
	}
	printf("\n Enter Matrix Element: \n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	if (lower_triangular_matrix(matrix,r,c))
		printf("\n Lower Triangular Matrix\n");
	else
		printf("\n Not A Lower Triangular Matrix \n");
	if (upper_triangular_matrix(matrix,r,c))
		printf("\n Upper Triangular Matrix\n");
	else
		printf("\n Not A Upper Triangular Matrix \n");
	if (diagonal_matrix(matrix,r,c))
		printf("\n Diagonal Matrix\n");
	else
		printf("\n Not A Diagonal Matrix \n");
	if (identity_matrix(matrix,r,c))
		printf("\n Identity Matrix\n");
	else
		printf("\n Not an Identity Matrix \n");
	if (tridiagonal_matrix(matrix,r,c))
		printf("\n Tridiagonal Matrix \n");
	else
		printf("\n Not a Tridiagonal Matrx \n");
	return 0;
}
int lower_triangular_matrix(int **matrix,int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if ((i < j) && (matrix[i][j] != 0))
				return 0;
		}
	}
	return 1;
}
int upper_triangular_matrix(int **matrix,int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if ((i > j) && (matrix[i][j] != 0))
				return 0;
		}
	}
	return 1;
}
int diagonal_matrix(int **matrix,int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if ((i != j) && (matrix[i][j] != 0))
				return 0;
		}
	}
	return 1;
}

int identity_matrix(int **matrix,int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if ( ((i != j) && (matrix[i][j] != 0)) || ((i == j) && (matrix[i][j] != 1)) )
				return 0;
		}
	}
	return 1;
}

int tridiagonal_matrix(int **matrix,int r,int c)
{
	int i,j;
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			if ((i == j) || (i-1 == j) || (i+1 == j))
			{
				if(matrix[i][j] == 0)
					return 0;
			}
			else
			{
				if (matrix[i][j] != 0)
					return 0;
			}
		}
	}
	return 1;
}

/* OUTPUT:-

TEST CASE 1:-

 Enter no. of row in a matrix: 4

 Enter no. of colum in a matrix: 4

 Enter Matrix Element:
1 4 0 0
3 4 1 0
0 2 3 4
0 0 1 3

 Not A Lower Triangular Matrix

 Not A Upper Triangular Matrix

 Not A Diagonal Matrix

 Not an Identity Matrix

 Tridiagonal Matrix
------------------------------------
TEST CASE 2:- 

 Enter no. of row in a matrix: 4

 Enter no. of colum in a matrix: 4

 Enter Matrix Element:

1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

 Lower Triangular Matrix

 Upper Triangular Matrix

 Diagonal Matrix

 Identity Matrix

 Not a Tridiagonal Matrx
------------------------------------
TEST CASE 3:-

 Enter no. of row in a matrix: 3

 Enter no. of colum in a matrix: 3

 Enter Matrix Element:

1 0 0
1 2 0
1 2 3

 Lower Triangular Matrix

 Not A Upper Triangular Matrix

 Not A Diagonal Matrix

 Not an Identity Matrix

 Not a Tridiagonal Matrx
*/