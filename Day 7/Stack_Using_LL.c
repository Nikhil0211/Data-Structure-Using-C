#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *push(struct node *,int );
struct node *pop(struct node *);
void display(struct node *);
int main()
{
	struct node *top;
	top=NULL;
	int i,n;
	do 
	{
		printf ("\n 1.Push");
		printf ("\n 2.Pop");
		printf ("\n 3.Display");
		printf ("\n 4.Exit ");
		printf ("\n Enter your choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("\n Enter a number: ");
					scanf("%d",&n);
					top=push(top,n);
					break;
			case 2: top=pop(top);
					break;
			case 3: printf("\n Stack is: ");
					display(top);
		}
	}while (i!=4);
	return 0;
}
struct node *push(struct node *top,int n)
{
	struct node *nw;
	nw=(struct node *)malloc(sizeof(struct node ));
	nw->data=n;
	nw->next=top;
	top=nw;
	return top;
}
void display(struct node *top)
{
	if (top==NULL)
	{
		printf("\n UnderFlow");
		return;
	}
	struct node *c;
	c=top;
	printf("\n");
	while(c!=NULL)
	{
		printf(" %d ",c->data);
		c=c->next;
	}
	printf("\n");
}
struct node *pop(struct node *top)
{
	if(top==NULL)
	{
		printf("\n UNDERFLOW ");
		return top;
	}
	else
	{
		struct node *c;
		c=top;
		top=c->next;
		free(c);
		return top;
	}
}
/*OUTPUT:-


 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 1

 Enter a number: 5

 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 1

 Enter a number: 2

 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 1

 Enter a number: 3

 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 3

Stack is: 3  2  5

 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 2

 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 3

Stack is: 2  5
 
 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 2

 1.Push
 2.Pop
 3.Display
 4.Exit
 Enter your choice: 3

Stack is: 5

1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 2

1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 2

Stack is: UNDERFLOW

1.Push
2.Pop
3.Display
4.Exit
Enter your choice: 4

*/
