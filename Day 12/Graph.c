#include<stdio.h>
#include<stdlib.h>

void edge(int**,int);

main()
{
	int v,i,j;
	int **a;
	printf("Enter the no of vertices= ");
	scanf("%d",&v);
	a=(int**)malloc(v*sizeof(int*));
	for(i=0;i<v;i++)
		a[i]=(int*)malloc(v*sizeof(int));
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			*(*(a+i)+j)=0;
	edge(a,v);
	printf("\nAdjacency Matrix\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
}

void edge(int **a,int v)
{
	int v1,v2,ch=1;
	printf("\n*** Vertices start from 1 ***\n");
	while(ch)
	{
		printf("Enter the vertices who are connected= ");
		scanf("%d%d",&v1,&v2);
		*(*(a+v1-1)+v2-1)=1;
		*(*(a+v2-1)+v1-1)=1;
		printf("Enter any no to continue adding edge or else enter 0 = ");
		scanf("%d",&ch);
	}
}

/* OUTPUT:- 

Enter the no of vertices= 4

*** Vertices start from 1 ***
Enter the vertices who are connected= 1 2
Enter any no to continue adding edge or else enter 0 = 1
Enter the vertices who are connected= 2 3
Enter any no to continue adding edge or else enter 0 = 1
Enter the vertices who are connected= 3 4
Enter any no to continue adding edge or else enter 0 = 1
Enter the vertices who are connected= 4 1
Enter any no to continue adding edge or else enter 0 = 0

Adjacency Matrix
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

*/
