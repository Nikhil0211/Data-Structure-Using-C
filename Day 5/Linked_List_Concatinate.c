#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *insert(struct node *,int );
struct node *concatinate(struct node *,struct node *);
void display(struct node *);
int main()
{
 	struct node *start,*start1;
 	start=NULL;
	start1=NULL;
	int i,n,pos,in;
	do
	{
		printf("1: Insert \n");
		printf("2: Concatinate two linked list\n");
		printf("3: Display \n");
		printf("4: Exit \n");
		printf("Enter Your Choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("1. Insert at List 1 \n");
					printf("2. Insert at List 2 \n");
					printf("Enter Your Choice: ");
					scanf("%d",&in);
					printf("\n Enter a number: ");
					scanf("%d",&n);
					if (in == 1)
						start=insert(start,n);
					else if (in == 2)
						start1=insert(start1,n);
					else 
						printf("\n Wrong Choice ");
					break;
			case 2: start = concatinate(start,start1);
					if (start == NULL)
						printf("\n Unsuccessful \n");
					else
						printf("\n Successful \n");
					break;
			case 3: printf("1. Display List 1 \n");
					printf("2. Display List 2 \n");
					printf("Enter Your Choice: ");
					scanf("%d",&in);
					if(in == 1)
					{
						display(start);
					}
					else if(in == 2)
					{
						display(start1);
					}
		}
	}while (i != 4);
 return 0;
}
struct node *insert(struct node *start,int n)
{
	struct node *nw,*p;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=n;
	nw->next=NULL;
	if (start==NULL)
	{
		start=nw;
	}
	else
	{
		p=start;
		while (p->next!=NULL)
		{
			p=p->next;
		}
		p->next=nw;
	}
	return start;
}
struct node *concatinate(struct node *start,struct node *start1)
{
	if (start == NULL && start1 == NULL)
	{
		printf("\n Both LIST are Empty ");
	}
	else
	{
		struct node *c;
		c=start;
		while (c->next!=NULL)
		{
			c=c->next;
		}
		c->next=start1;
	}
return start;
}
void display(struct node *start)
{
	struct node *p;
	p=start;
	if (p==NULL)
	{
		printf ("\n LIST IS EMPTY \n");
	}
	else
	{
		while (p!=NULL)
		{
			printf (" %d ",p->data);
			p=p->next;
		}
	}
	printf("\n");
}

/* 
OUTPUT:-

1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 1
1. Insert at List 1
2. Insert at List 2
Enter Your Choice: 1

 Enter a number: 1
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 1
1. Insert at List 1
2. Insert at List 2
Enter Your Choice: 1

 Enter a number: 2
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 1
1. Insert at List 1
2. Insert at List 2
Enter Your Choice: 1

 Enter a number: 3
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 3
1. Display List 1
2. Display List 2
Enter Your Choice: 1
 1  2  3

1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 1
1. Insert at List 1
2. Insert at List 2
Enter Your Choice: 2

 Enter a number: 4
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 1
1. Insert at List 1
2. Insert at List 2
Enter Your Choice: 2

 Enter a number: 5
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 1
1. Insert at List 1
2. Insert at List 2
Enter Your Choice: 2

 Enter a number: 6
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 3
1. Display List 1
2. Display List 2
Enter Your Choice: 2
 4  5  6
 
1: Insert
2: Concatinate two linked list
3: Display
4: Exit
Enter Your Choice: 2
 Successful
 
 */
