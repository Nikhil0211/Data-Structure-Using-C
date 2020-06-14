#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node 
{
	int data;
	struct node *left, *right;
};
struct node *insert(struct node *,int );
int no_of_node(struct node *);
int no_of_leaf(struct node *);
int height (struct node *);
int search (struct node *,int);
struct node* deleteNode(struct node *, int ); 
struct node *minValueNode(struct node*);
void pre_order(struct node *);
void in_order(struct node *);
void post_order(struct node *);
int main()
{
	struct node *root;
	root = NULL;
	int i, n, tra, count, h, found;
	do 
	{	
		printf("\n1. Insert ");
		printf("\n2. Traversal");
		printf("\n3. Count No. of Node");
		printf("\n4. Count No. of Leaf Node");
		printf("\n5. Find Height of a Tree");
		printf("\n6. Search A Number");
		printf("\n7. Remove A Node");
		printf("\n8. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf ("\n Enter a Number: ");
					scanf("%d",&n);
					root = insert(root,n);
					break;
			case 2: printf("\t\n1. Pre order Traversal");
					printf("\n2. In Order Traversal");
					printf("\n3. Post Order Traversal");
					printf("\nEnter your choice: ");
					scanf("%d",&tra);
					printf("\n Tree Element(Nodes) are: ");
					if (tra == 1)
					 pre_order(root);
					else if (tra == 2)
					 in_order(root);
					else if (tra == 3)
					 post_order(root);
					printf("\n");
					break;
			case 3: count = no_of_node(root);
					printf("\n No of nodes in a Tree is : %d",count);
					printf("\n");
					break;
			case 4: count = no_of_leaf(root);
					printf("\n No of leaf node in a Tree is : %d",count);
					printf("\n");
				    break;
			case 5: h = height(root);
				    printf("\n Height of Tree is : %d",h);
					printf("\n");
					break;
			case 6: printf("\n Enter a number to search: ");
					scanf("%d",&n);
					found = search(root,n);
					if (found == -1)
					 printf("\n NOT FOUND ");
					else
					 printf("\n FOUND ");
					printf("\n");
					break;
			case 7: printf("\n Enter a number to Delete: ");
					scanf("%d",&n);
					root = deleteNode(root,n);
		}
	}while (i != 8);
	return 0;
}
struct node *insert(struct node *root,int n)
{
	struct node *nw;
	nw = (struct node *) malloc (sizeof (struct node ));
	nw->data = n;
	nw->left = NULL;
	nw->right = NULL;
	if (root == NULL)
	{
		root = nw;
	}
	else if (n < root->data)
	{
		root->left = insert(root->left,n);
	}
	else
	{
		root->right = insert(root->right,n);
	}
return root;
}
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
struct node * minValueNode(struct node* node) 
{ 
    struct node* current ;
	 current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 
int no_of_node (struct node *root)
{
	if (root == NULL)
	 return 0;
	else
	 return 1 + no_of_node(root->left) + no_of_node(root->right);
}
int no_of_leaf(struct node *root)
{
	if (root == NULL)
	 return 0;
	else if (root->left == NULL && root->right == NULL)
	 return 1;
    else 
     return no_of_leaf(root->left) + no_of_leaf(root->right);
}
int height(struct node *root)
{
	if (root == NULL)
	 return 0;
	else
	{
		int c;
		c = no_of_node(root);
		return (log2(c) + 1);
	}
}
int search(struct node *root,int n)
{
	int find = -1;
	while (root != NULL)
	{
		if (root->data == n)
		{
			find = 0;
			break;
		}
		else if (root->data > n)
		{
			root = root->left;
		}
		else 
		{
			root = root->right;
		}
	}
	return find;
}
void pre_order(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ",root->data);
		pre_order(root->left);
		pre_order(root->right);
    }
}
void in_order(struct node *root)
{
	if (root != NULL)
	{
		pre_order(root->left);
		printf("%d ",root->data);
		pre_order(root->right);
    }
}
void post_order(struct node *root)
{
	if (root != NULL)
	{
		pre_order(root->left);
		pre_order(root->right);
		printf("%d ",root->data);
    }
}

/* OUTPUT:-


1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 1

 Enter a Number: 39

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 1

 Enter a Number: 56

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 1

 Enter a Number: 54

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 1

 Enter a Number: 78

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 1

 Enter a Number: 55

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 1

 Enter a Number: 80

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 2

1. Pre order Traversal
2. In Order Traversal
3. Post Order Traversal
Enter your choice: 1

 Tree Element(Nodes) are: 45 39 56 54 55 78 80

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 2

1. Pre order Traversal
2. In Order Traversal
3. Post Order Traversal
Enter your choice: 2

 Tree Element(Nodes) are: 39 45 56 54 55 78 80

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 2

1. Pre order Traversal
2. In Order Traversal
3. Post Order Traversal
Enter your choice: 3

 Tree Element(Nodes) are: 39 56 54 55 78 80 45

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 3

 No of nodes in a Tree is : 7

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 4

 No of leaf node in a Tree is : 3

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 5

 Height of Tree is : 3

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 6

 Enter a number to search: 56

 FOUND

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 6

 Enter a number to search: 88

 NOT FOUND

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 7

 Enter a number to Delete: 39

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 2

1. Pre order Traversal
2. In Order Traversal
3. Post Order Traversal
Enter your choice: 1

 Tree Element(Nodes) are: 45 56 54 55 78 80

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 7

 Enter a number to Delete: 54

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 2

1. Pre order Traversal
2. In Order Traversal
3. Post Order Traversal
Enter your choice: 1

 Tree Element(Nodes) are: 45 56 55 78 80

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 7

 Enter a number to Delete: 56

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 2

1. Pre order Traversal
2. In Order Traversal
3. Post Order Traversal
Enter your choice: 1

 Tree Element(Nodes) are: 45 78 55 80

1. Insert
2. Traversal
3. Count No. of Node
4. Count No. of Leaf Node
5. Find Height of a Tree
6. Search A Number
7. Remove A Node
8. Exit
Enter Your Choice: 8

*/
