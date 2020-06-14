#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *pre;
	int data;
	struct node *next;
};
struct node *insert(struct node *,int );
struct node *insert_at_beginning(struct node *,int );
struct node *insert_at_position(struct node *,int ,int );
struct node *delete_1st_node(struct node *);
struct node *delete_last_node(struct node *);
struct node *delete_AtPOS(struct node *,int );
void display(struct node *);
int count(struct node *);
int main()
{
	struct node *start;
	start=NULL;
	int i,n,mpos;
	start=NULL;
	do 
	{
		printf ("\n1.Insert");
		printf ("\n2.Insert at Beginning");
		printf ("\n3.Insert at Position");
		printf ("\n4.Delete 1st Node ");
		printf ("\n5.Delete Last Node ");
		printf ("\n6.Delete At Position");
		printf ("\n7.Display");
		printf ("\n8.Exit ");
		printf ("\nEnter your choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("\nEnter a number: ");
				   scanf("%d",&n);
				   start= insert(start,n);
				   break;
			case 2:printf("\nEnter a number: ");
				   scanf("%d",&n);
				   start=insert_at_beginning(start,n);
				   break;
			case 3:printf("\nEnter a number: ");
				   scanf("%d",&n);
				   printf("\nEnter a position: ");
				   scanf("%d",&mpos);
				   start=insert_at_position(start,n,mpos);
				   break;	
			case 4:start=delete_1st_node(start);
					break;
			case 5:start=delete_last_node(start);
					break;				   
			case 6:printf("\nEnter a position: ");
				   scanf("%d",&mpos);
			       start=delete_AtPOS(start,mpos);
			       break;
			case 7:display(start);
		}
	}
	while (i!=8);
	return 0;
}
struct node *insert (struct node *start,int n)
{
	struct node *nw,*c;
	nw=(struct node *)malloc(sizeof(struct node));
    nw->data=n;
    if (start == NULL)
    {
    	nw->next=NULL;
    	nw->pre=NULL;
    	start=nw;
	}
	else
	{
		c=start;
		while (c->next!=NULL)
		{
			c=c->next;
		}
		c->next=nw;
		nw->pre=c;
		nw->next=NULL;
	}
	return start;
}
struct node *insert_at_beginning(struct node *start,int n)
{
	struct node *nw,*c;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=n;
	if(start == NULL)
	{
		start=nw;
		nw->next=NULL;
		nw->pre=NULL;
	}
	else
	{
		c=start;
		nw->next=start;
		nw->pre=NULL;
		c->pre=nw;
		start=nw;
	}
	return start;
}
struct node *insert_at_position(struct node *start,int n,int pos)
{
	int counts=count(start);
	struct node *nw,*c;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=n;
	if (start == NULL)
	{
	   if (pos==1)
	   {
	   	nw->next=NULL;
	   	nw->pre=NULL;
	   	start=nw;
	   }
	   else
	   {
	   	printf("\n Empty List ");
	   }
	}
	else
	{
		c=start;
		if (pos-1==0)
		{
			nw->next=start;
			nw->pre=NULL;
			start=nw;
		}
		else if (pos-1==counts)
		{
			while(c->next!=NULL)
			{
				c=c->next;
			}
			nw->pre=c;
			nw->next=NULL;
			c->next=nw;
		}
		else
		{
			counts=0;
			while(counts<pos-1 && c->next!=NULL)
			{
				c=c->next;
				counts++;
			}
			if (c==NULL)
			{
				printf("\n Invalid position ");
			}
			else
			{
				nw->pre=c->pre;
				nw->next=c->pre->next;
				c->pre->next=nw;
				c->pre=nw;
			}
		}
	}
	return start;
}
struct node *delete_1st_node(struct node *start)
{
	struct node *c;
	c=start;
	if (start == NULL)
	{
		printf ("Empty List\n");
	}
	else if (c->next==NULL)
	{
		start=NULL;
		free(c);
	}
	else
	{
		start=c->next;
		c->next->pre=NULL;
		c->next=NULL;
		free(c);
	}
	return start;
}
struct node *delete_last_node(struct node *start)
{
	struct node *c;
	c=start;
	if (start==NULL)
	{
		printf("Empty List\n");
	}
	else if (c->next==NULL)
	{
		start=NULL;
		free(c);
	}
	else
	{
		while (c->next!=NULL)
		{
			c=c->next;
		}
		c->pre->next=NULL;
		c->pre=NULL;
		free(c);
	}
	return start;
}
struct node *delete_AtPOS(struct node *start,int pos)
{
	struct node *c,*p;
	int count=0;
	c=start;
	if (start==NULL)
	{
		printf ("\n Empty list \n");
	}
	else
	{
		while (c!=NULL)
		{
			count++;
			if (count == pos)
			{
				if (pos==1)
				{
					start=c->next;
					c->next->pre=NULL;
					free(c);
					break;
				}
				else
				{
					p->next=c->next;
					if(c->next!=NULL)
					{
						c->next->pre=p;
					}
					free(c);
					break;
				}
			}
			else
			{
				p=c;
				c=c->next;
			}
		}
		if (count!=pos)
		 printf ("\nINVALID POSITION");
    }
    return start;
}
void display(struct node *start)
{
  struct node *c;
  c=start;
  if (start==NULL)
  {
  	printf ("\n Empty List \n");
  }
  else
  {
   while (c!=NULL)
   {
  	printf(" %d ",c->data);
  	c=c->next;
   } 
  }
}
int count(struct node *start)
{
	int counts=0;
	struct node *c;
	c=start;
	while (c!=NULL)
	{
		counts++;
		c=c->next;
	}
    return counts;
}

/* 
OUTPUT:-

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 1

Enter a number: 1

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 1

Enter a number: 2

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 1

Enter a number: 3

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 7
 1  2  3
1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 2

Enter a number: 5

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 7
 5  1  2  3
1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 3

Enter a number: 2

Enter a position: 1

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 7
 2  5  1  2  3
 
1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 4

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 7
 5  1  2  3

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 5

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 7
 5  1  2

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 6

Enter a position: 2

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 7
 5  2

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 6

Enter a position: 3

INVALID POSITION

1.Insert
2.Insert at Beginning
3.Insert at Position
4.Delete 1st Node
5.Delete Last Node
6.Delete At Position
7.Display
8.Exit
Enter your choice: 8

*/
