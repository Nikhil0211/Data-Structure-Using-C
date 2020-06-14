#include <stdio.h> 

void towerOfHanoi(int , char , char , char );
int main() 
{ 
	int n;
	printf("\n Enter No. of Disk: ");
	scanf("%d",&n);
	towerOfHanoi(n, 'A', 'C', 'B'); 
	return 0; 
} 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
		return; 
	} 
	else if (n == 0)
	{
		printf("\n No Move Require ");
		return; 
	} 	
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod); 
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod); 
} 

/* OUTPUT:-
Test case 1:-

 Enter No. of Disk: 0

 No Move Require
--------------------------------
Test case 2:-

 Enter No. of Disk: 1

 Move disk 1 from rod A to rod C
--------------------------------
Test case 3:-

 Enter No. of Disk: 2

 Move disk 1 from rod A to rod B
 Move disk 2 from rod A to rod C
 Move disk 1 from rod B to rod C
--------------------------------
Test case 4:-

 Enter No. of Disk: 3

 Move disk 1 from rod A to rod C
 Move disk 2 from rod A to rod B
 Move disk 1 from rod C to rod B
 Move disk 3 from rod A to rod C
 Move disk 1 from rod B to rod A
 Move disk 2 from rod B to rod C
 Move disk 1 from rod A to rod C
*/
