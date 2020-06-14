#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *insert(struct node *,int );
struct node *insert_at_beg(struct node *,int );
struct node *insert_at_pos(struct node *,int,int );
struct node *delete_last(struct node *);
struct node *delete_at_beg(struct node *);
struct node *delete_at_pos(struct node *,int );
void display(struct node *);

int main ()
{
	struct node *start;
	start=NULL;
	int i,n,pos;
	do 
	{
		printf("\n1. Insert ");
		printf("\n2. Insert at Beginning");
		printf("\n3. Insert at any position ");
		printf("\n4. Delete Last element ");
		printf("\n5. Delete at Beginning ");
		printf("\n6. Delete at any position");
		printf("\n7. Display");
		printf("\n8. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&i);
		switch (i)
		{
			case 1: printf("\n Enter a number: ");
					scanf("%d",&n);
					start = insert(start,n);
					break;
			case 2: printf("\n Enter a number: ");
					scanf("%d",&n);
					start = insert_at_beg(start,n);
					break;
			case 3: printf("\n Enter a number: ");
					scanf("%d",&n);
					printf("\n Enter Position: ");
					scanf("%d",&pos);
					start = insert_at_pos(start,n,pos);
					break;
			case 4: start = delete_last(start);
					break;
			case 5: start = delete_at_beg(start);
					break;
			case 6: printf("\n Enter position: ");
					scanf("%d",&pos);
					start = delete_at_pos(start,pos);
					break;
			case 7: printf("\n List is:");
					display(start);
		}
	}while (i!=8);
return 0;
}
struct node *insert (struct node *start, int n)
{
	struct node *nw;
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data = n;
	nw->next = start;
	if (start == NULL)
	{
		start = nw;
		nw->next = start;
	}
	else
	{
		struct node *c;
		c = start;
		while (c->next != start)
		{
			c = c->next;
		}
		c->next = nw;
	}
return start;
}
struct node *insert_at_beg(struct node *start,int n)
{
	struct node *nw,*c;
	nw = (struct node *)malloc(sizeof(struct node));
	nw->data = n;
	if (start == NULL)
	{
		start = nw;
		nw = start;
	}
	else
	{
		struct node *c;
		c = start;
		while (c->next != start)
		{
			c = c->next;
		}
		nw->next = start;
		start=nw;
		c->next=start;
	}
return start;
}
struct node *insert_at_pos(struct node *start,int n,int pos)
{
	struct node *nw,*cur,*pre,*c;
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
		c=start;
		do
		{
			count++;
			if (count == pos)
			{
				if (pos == 1)
				{
					nw->next=start;
					while (c->next != start)
					{
						c=c->next;
					}
					c->next = nw;
					start = nw;
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
		}while (cur != start);
	    if (count+1 == pos)
	    {
	    	start = insert(start,n);
		}
		else if (count < pos)
	    {
	    	printf("\n Enter a valid Position \n");
		}
		
	}
	return start;
}
struct node *delete_last(struct node *start)
{
	struct node *c,*p;
	p=start;
	c=start;
	if (start==NULL)
	{
		printf("\n EMPTY LIST \n\n ");
		return start;
	}
	else if (c->next == start)
	{
		free(c);
		return NULL;
	}
	do
	{
		p=c;
		c=c->next;
	}while (c->next!=start);
	p->next=start;
	free(c);
	return start;
}
struct node *delete_at_beg(struct node *start)
{
	struct node *c,*first;
	c=start;
	first=start;
	if (start == NULL)
	{
		printf("\n Empty List \n\n");
		return;
	}
	else if (first->next == start)
	{
		start = NULL;
		free(first);
	}
	else
	{
		do
		{
		 c=c->next;	
		}while(c->next != start);
		start=first->next;
		c->next=start;
		free(first);
	}
	return start;

}
struct node *delete_at_pos(struct node *start,int pos)
{
	struct node *c,*p,*cur;
	int count=0;
	if (start==NULL)
	{
		printf("\n EMPTY LIST \n\n");
		return start;
	}
	c=start;
	p=start;
	cur=start;
	do	
	{
		count++;
		if (count==pos)
		{
			if (pos==1)
			{
				if (cur->next == start)
				{
					start = NULL;
				}
				else
				{
					do 
					{
						cur=cur->next;
					}while (cur->next!=start);
					start=c->next;
					cur->next=start;
					free(c);
				}
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
	}while(c!=start);
	if (count<pos)
	{
		printf("\n INVALID POSITION \n\n");
	}
	return start;
}
void display(struct node *start)
{
	if (start != NULL)
	{
		struct node *c;
		c = start;
		do
		{
			printf(" %d",c->data);
			c = c->next;
	 	}while (c != start);
	}
	else 
	{
		printf(" Empty");
	}
	printf("\n");
}
/* OUTPUT:- 

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 1

 Enter a number: 1

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 1

 Enter a number: 2

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 1 2

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 2

 Enter a number: 5

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 5 1 2

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 3

 Enter a number: 2

 Enter Position: 1

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 2 5 1 2
 
1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 3

 Enter a number: 5

 Enter Position: 5

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 2 5 1 2 5

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 4

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 2 5 1 2
 
1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 5

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 5 1 2
 
1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 6

 Enter position: 2

1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 7

 List is: 5 2

 1. Insert
2. Insert at Beginning
3. Insert at any position
4. Delete Last element
5. Delete at Beginning
6. Delete at any position
7. Display
8. Exit
Enter Your Choice: 8
*/ 
