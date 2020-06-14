#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stk
{
	int top;
	int arr[MAX];
};
typedef struct stk stack;

void push (stack *,int );
int pop (stack *);
int isEmpty(stack *);
int isFull(stack *);
int peek(stack *);

int main()
{
	stack *s;
	s=(stack *)malloc(sizeof(stack));
	s->top = -1;
	int i,n,t,num;
	do
	{
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Check Top Element");
		printf("\n4. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("\n Enter a number: ");
					scanf("%d",&n);
					push(s,n);
					break;
			case 2: num = pop(s);
					if (num != -1)
					{
						printf("\n removed: %d\n",num);
					}
					break;
			case 3: t = peek(s);
					if (t!=-1)
						printf("\nTop = %d\n",t);
					else
						printf("\n Empty\n");
		}
	}while (i!=4);
	return 0;
}
void push(stack *s,int n)
{
	if (isFull(s))
	{
		printf("\n Overflow");
	}
	else 
	{
		s->arr[++(s->top)] = n;
	}
}
int pop(stack *s)
{
	if (isEmpty(s))
	{
		printf("\n Underflow");
		return -1;
	}
	else 
	{
		return s->arr[(s->top)--];
	}
}
int isFull(stack *s)
{
	if (s->top == MAX-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int isEmpty(stack *s)
{
	if (s->top == -1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int peek(stack *s)
{
	return s->arr[s->top];
}

/* OUTPUT:- 
1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 5

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 2

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 3

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 3

Top = 3

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 2

 removed: 3

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 2

 removed: 2

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 2

 removed: 5

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 2

 Underflow
 
 1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 1

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 2

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 3

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 4

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 5

1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 1

 Enter a number: 6

 Overflow


1. Push
2. Pop
3. Check Top Element
4. Exit
Enter Your Choice: 4

*/
