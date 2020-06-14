#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *insert(struct node *,int );
struct node *insert_beg(struct node *,int );
struct node *insert_A_pos(struct node *,int ,int );
struct node *insert_B_pos(struct node *,int ,int );
struct node *del(struct node *);
struct node *del_end(struct node *);
struct node *del_at_pos(struct node *,int pos);
int search(struct node *,int );
int count_node(struct node *);
struct node * reverse(struct node *);
void display(struct node *);
int main()
{
 	struct node *start;
 	start=NULL;
	int i,n,pos;
	do
	{
		printf("1: Insert \n");
		printf("2: Insert at Beganning \n");
		printf("3: Insert after a position \n");
		printf("4: Insert befor a position \n");
		printf("5: Delete first node \n");
		printf("6: Delete last node \n");
		printf("7: Delete a node at position \n");
		printf("8: Search a number \n");
		printf("9: Count number of node \n");
		printf("10: Reverse a list \n");
		printf("11: Display \n");
		printf("12: Exit \n");
		printf("Enter Your Choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("\n Enter a number: ");
					scanf("%d",&n);
					start=insert(start,n);
					break;
			case 2: printf("\n Entaer a number: ");
			        scanf("%d",&n);
			        start=insert_beg(start,n);
			        break;
			case 3: printf ("\n Enter a number: ");
					scanf("%d",&n);
					printf ("\n Enter a position: ");
					scanf("%d",&pos);
					start=insert_A_pos(start,n,pos);
					break;
			case 4: printf ("\n Enter a number: ");
					scanf("%d",&n);
					printf ("\n Enter a position: ");
					scanf("%d",&pos);
					start=insert_B_pos(start,n,pos);
					break;
			case 5: start = del(start);
					break;
			case 6: start= del_end(start);	
			        break;
			case 7: printf("\n Enter position: ");
					scanf("%d",&pos);
					start=del_at_pos(start,pos);
					break;
			case 8: printf("\n Enter a number to search: ");
					scanf("%d",&n);
					pos=search(start,n);
					if (pos==-1)
				    {
				    	printf("\n Not Found \n\n");
					}
					else if (pos==-2)
					{
						printf("\n Empty List \n\n");
					}
					else
					{
						printf("\n Found at %d\n\n",pos+1);
					}
					break;
			case 9: pos=count_node(start);
			        printf("\n No. Of node = %d \n\n",pos);
					break;
			case 10: printf("\n List Before Reverse: ");
					 display(start);
					 printf("\n");
					 start=reverse(start);
					 printf("\n List After Reverse: ");
					 display(start);
					 printf("\n\n");
					 break;	
		    case 11:display(start);
		    	   printf("\n");
		    	   break;
		}
	}while(i!=12);
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
struct node *insert_beg(struct node *start,int n)
{
	struct node *nw;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=n;
	nw->next=start;
	start=nw;
	return start;
}
struct node *insert_A_pos(struct node *start,int n,int pos)
{
	struct node *nw,*cur,*pre;
	int count=0;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=n;
	if (start==NULL)
	{
		printf("\n Empty List ");
		return;
	}
	else
	{
		pre=start;
		cur=start;
		while (cur!=NULL)
		{
			count++;
			if (count==pos)
			{
				nw->next=cur->next;
				cur->next=nw;
			    break;
			}
			cur=cur->next;
		}
	    if (count < pos)
	    {
	    	printf("\n Enter a valid Position \n");
		}
	}
	return start;
}
struct node *insert_B_pos(struct node *start,int n,int pos)
{
	struct node *nw,*cur,*pre;
	int count=0;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=n;
	if (start==NULL)
	{
		printf("\n Empty List ");
		return;
	}
	else
	{
		pre=start;
		cur=start;
		while (cur!=NULL)
		{
			count++;
			if (count==pos)
			{
				if (pos==1)
				{
					nw->next=start;
					start=nw;
				}
				else
				{
				 nw->next=pre->next;
				 pre->next=nw;
				}
			    break;
			}
			pre=cur;
			cur=cur->next;
		}
	    if (count < pos)
	    {
	    	printf("\n Enter a valid Position \n");
		}
	}
	return start;
}
struct node *del(struct node *start)
{
	struct node *c;
	c=start;
	if (start == NULL)
	{
		printf("\n Empty List \n\n");
		return;
	}
	start=c->next;
	free(c);
	return start;
}
struct node *del_end(struct node *start)
{
	struct node *c,*p;
	p=start;
	c=start;
	if (start==NULL)
	{
		printf("\n EMPTY LIST \n\n ");
		return start;
	}
	else if (c->next == NULL)
	{
		start = NULL;
		free(c);
		return start;
	}
	while(c->next!=NULL)
	{
		p=c;
		c=c->next;
	}
	p->next=NULL;
	free(c);
	return start;
}
struct node *del_at_pos(struct node *start,int pos)
{
	
	struct node *c,*p;
	int count=0;
	if (start==NULL)
	{
		printf("\n EMPTY LIST \n\n");
		return start;
	}
	c=start;
	p=start;
	while (c!=NULL)
	{
		count++;
		if (count==pos)
		{
			if (pos==1)
			{
				start=c->next;
				free(c);
			}
			else
			{
			 p->next=c->next;
			 free(c);	
			}
			break;
		}
		p=c;
		c=c->next;
	}
	if (count<pos)
	{
		printf("\n INVALID POSITION \n\n");
	}
	return start;
}
int search(struct node * start,int n)
{
	struct node *c;
	int count=0;
	if (start==NULL)
	{
		return -2;
	}
	c=start;
	while (c!=NULL)
	{
		if (c->data==n)
		{
		  return count;
		}
		else
		{
			count++;
		}
		c=c->next;
	}
	if (count>0)
	{
		return -1;
	}
}
int count_node(struct node *start)
{
	int count=0;
	struct node *c;
	c=start;
	while (c!=0)	
	{
		count++;
		c=c->next;
	}
	return count;
}
struct node *reverse(struct node *start)
{
	struct node *cur,*pre,*next;
	cur=start;
	pre=NULL;
	while(cur!=NULL)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	start=pre;
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
}
/*
OUTPUT:-

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 1

 Enter a number: 1
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 1

 Enter a number: 2
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 1

 Enter a number: 3
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 1  2  3
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 2
Entaer a number: 5

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 5  1  2  3

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 3

 Enter a number: 2
 Enter a position: 1

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 
 5  2  1  2  3
 
11: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 4

 Enter a number: 11
 Enter a position: 1

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 11  5  2  1  2  3
 
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 5

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 5  2  1  2  3
 
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 6

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11

 5  2  1  2
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 7

 Enter position: 1

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at positi
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 2  1  2 
 
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 8

 Enter a number to search: 1
 Found at 2
 
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 8

 Enter a number to search: 5
 Not Found
  
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 9
 No. Of node = 3


1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 2
Entaer a number: 5

1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 10

 List Before Reverse:  5  2  1  2 

 List After Reverse:   2  1  2  5
 
1: Insert
2: Insert at Beganning
3: Insert after a position
4: Insert befor a position
5: Delete first node
6: Delete last node
7: Delete a node at position
8: Search a number
9: Count number of node
10: Reverse a list
11: Display
12: Exit
Enter Your Choice: 11
 2  1  2  5
 
*/
