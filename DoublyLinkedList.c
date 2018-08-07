/*
	This program creates a doubly-linked list.
	Through a menu, then nodes can be added at the beginning or end or before/after a specific node.
	Also, any specific node in between or in the beginning or at the end can be deleted.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct dll
{
	int data;
	struct dll* left;
	struct dll* right;
}*s;

void create()
{
	int n, data, i;
	struct dll *Node, *p;

	printf("Enter size of linked-list : ");
	scanf("%d",&n);

	s = (struct dll*)malloc(sizeof(struct dll));

	if(s == NULL)
	{
		printf("Memory could not be located for the linked list!!!");
	}
	else
	{
		printf("\tData at node 1 : ");
		scanf("%d",&(s->data));
		s->left = NULL;
		s->right = NULL;

		p = s;

		i=2;
		while(i<=n)
		{
			Node = (struct dll*)malloc(sizeof(struct dll));
			if(Node == NULL)
			{
				printf("Memory could not be located to this node!!!!");
				break;
			}
			else
			{
				printf("\tData at Node %d : ",i);
				scanf("%d",&(Node->data));
				Node->right = NULL;
				Node->left = p;
				p->right = Node;
				p = p->right;
			}
			i++;
		}

		printf("Doubly Linked List Created!!!\n\n");
	}
}

void disp()
{
	struct dll* p;
	printf("Doubly Linked List :\n");
	if(s==NULL)
	{
		printf("Empty Doubly Linked List!!!\n");
	}
	else
	{
		p = s;
		int i=1;
		while(p!=NULL)
		{
			printf("\t%2d. %2d\n",i,p->data);
			p = p->right;
			i++;
		}
	}
}

bool insertBefore(int x, int data)
{
	bool flag = false;
	struct dll *p = s, *q;
	q = (struct dll*)malloc(sizeof(struct dll));
	q->data = data;
	
	while(p!=NULL)
	{
		if(p->data==x)
		{
			q->right = p;
			q->left = p->left;
			if(p->left!=NULL)
			{
				p->left->right = q;
			}
			p->left = q;
			printf("\nInserted a node before %d...\n",x);
			flag = true;
			break;
		}
		else
		{
			p = p->right;
		}
	}
	return flag;
}

bool insertAfter(int x, int data)
{
	bool flag = false;
	struct dll *p = s, *q;
	q = (struct dll*)malloc(sizeof(struct dll));
	q->data = data;
	
	while(p!=NULL)
	{
		if(p->data==x)
		{
			q->right = p->right;
			q->left = p;
			if(p->right!=NULL)
			{
				p->right->left = q;
			}
			p->right = q;
			printf("\nInserted a node after %d...\n",x);
			flag = true;
			break;
		}
		else
		{
			p = p->right;
		}
	}
	return flag;
}

bool deletex(int data)
{
	bool flag = false;
	struct dll *p = s;
	if(s!=NULL)
	{
		while(p!=NULL)
		{
			if(p->data==data)
			{
				p->left->right = p->right;
				p->right->left = p->left;
				printf("\nDeleted a node with value = %d...\n",data);
				flag = true;
				break;
			}
			else
			{
				p = p->right;
			}
		}
	}
	else
	{
		printf("Empty List!!!\n");
	}
	return flag;
}

void deleteFirstNode()
{
	if(s!=NULL)
	{
		s = s->right;
		s->left = NULL;
		printf("\nDeleted the first node...\n");
	}
	else
	{
		printf("Empty List!!!\n");
	}
}

void deleteLastNode()
{
	struct dll *p=s;
	if(s!=NULL)
	{
		while(p->right->right!=NULL)
		{
			p = p->right;
		}
		p->right = NULL;
		printf("\nDeleted the last node...\n");
	}
	else
	{
		printf("Empty List!!!\n");
	}
}

int main()
{
	int choice, x, data;
	create();
	
	while(1)
	{
		printf("\n\n\tM  E  N  U\n1. Insert x before a specific value\n2. Insert x after a specific value\n3. Delete a specific value\n4. Delete the first node\n5. Delete the last node\n6. Display the linked list : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1 :
				printf("Enter a number of the list : ");
				scanf("%d",&x);
				printf("Enter data to be put before the first occurence of %d : ",x);
				scanf("%d",&data);
				if(insertBefore(x,data))
					printf("Inserted!!\n");
				else
					printf("%d not found\n",x);
				break;

			case 2 :
				printf("Enter a number of the list : ");
				scanf("%d",&x);
				printf("Enter data to be put after the first occurence of %d : ",x);
				scanf("%d",&data);
				if(insertAfter(x,data))
					printf("Inserted!!\n");
				else
					printf("%d not found\n",x);
				break;

			case 3 :
				printf("Enter a number of the list : ");
				scanf("%d",&x);
				if(deletex(x))
					printf("Deleted %d!!\n",x);
				else
					printf("%d not found\n",x);
				break;

			case 4 :
				deleteFirstNode();
				break;

			case 5 :
				deleteLastNode();
				break;

			case 6 :
				disp();
				break;

			default :
				break;
		}
	}
	return 0;
}
