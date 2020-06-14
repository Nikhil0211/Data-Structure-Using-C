#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct stk
{
	int top;
	char arr[MAX];
};
typedef struct stk stack;
int valid_exp(stack *,char []);
void in_to_post(stack *,char []);
int getprese(char );
void push (stack *,char );
char pop (stack *);
int isEmpty(stack *);
int isFull(stack *);
char peek(stack *);
int main()
{
	stack *s;
	int i;
	char ch[MAX],c;
	s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	printf ("\n Enter an infix expression: ");
	scanf("%[^\n]",ch);
	if (valid_exp(s,ch))
	{ 
	 	in_to_post(s,ch);
	}
	else
	{
		printf ("\n enter a valid infix expression ");
	}
	return 0;
}
int valid_exp(stack *s,char ch[])
{
	int i,f=1;
	char c; 
	for (i=0;i<MAX;i++)
	{
		if (ch[i]=='(' || ch[i]== '{' || ch[i]== '[')
		{
			push(s,ch[i]);
		}
	    else if (ch[i]==')' || ch[i]== '}' || ch[i]== ']')
	    {
	        if(isEmpty(s))
			{
				f=0;
		    } 
	    	c=pop(s);
	        if (ch[i] == ')' && (c == ']' || c == '}') )
	        {
	          f=0;
			}
			else if (ch[i] == ']' && (c == ')' || c == '}'))
			{
				f=0;
			}
			else if (ch[i] == '}' && (c == ']' || c == ')'))
			{
				f=0;
			}
		
		}
	}
	if (s->top >= 0)
	{
		f=0;
	}
 return f;
}
void in_to_post(stack *s,char ch[])
{
	int i;
	char c;
	for (i=0;i<MAX;i++)
	{
		if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/' || ch[i] == '%' || ch[i]=='(' || ch[i]== '{' || ch[i]== '[' )
		{
			if (isEmpty(s) || ch[i] == '(')
			{
				push (s,ch[i]);
			}
			else
			{
				c = peek(s);
				if (getprese(c)<getprese(ch[i]) || c == '(')
				{
					push (s,ch[i]);
				}
				else 
				{
					while (getprese(c)>=getprese(ch[i]))
					{
						printf ("%c",c);
						pop(s);
						if (isEmpty(s))
						{
							push(s,ch[i]);
							break;
						}
						c=peek(s);
					
					}
				}
			}
		}
	 else
		 {
		 	printf("%c",ch[i]);
		 }
	}
	while(!isEmpty(s))
	{
		printf("%c",pop(s));
	}
}
void push(stack *s,char c)
{
	if (isFull(s))
	{
		printf("\n Overflow");
	}
	else 
	{
		s->arr[++(s->top)] = c;
	}
}
char pop(stack *s)
{
	if (isEmpty(s))
	{
		printf("\n Underflow");
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
int getprese(char ch)
{
	if (ch == ')' || ch == '}' || ch == ']')
	{
		return 3;
	}
	if (ch == '*' || ch == '/' || ch == '%')
	{
		return 2;
	}
	else if (ch == '+'||ch == '-')
	{
		return 1;
	}
}
char peek(stack *s)
{
	return s->arr[s->top];
}
/* OUTPUT:- 

 Enter an infix expression: a+b*c/d
abc*+

*/
