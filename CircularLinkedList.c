/*
	This program creates and displays a circular-linked list.
*/
#include<stdio.h>
#include<stdlib.h>

struct cll {
	int data;
	struct cll *next;
}*s;

void create(int n)
{
	s = (struct cll*)malloc(sizeof(struct cll));
	int i=2;
	struct cll *p=s, *Node1;

	if(s==NULL)
	{
		printf("No memory allocated to the circular linked list\n");
	}
	else
	{
		printf("Data at node 1 : ");
		scanf("%d",&(s->data));

		while(i<=n)
		{
			Node1 = (struct cll*)malloc(sizeof(struct cll));
            if(Node1 == NULL)
            {
                printf("Memory not located");
                break;
            }
            else
            {
				printf("Data at node %d : ",i++);
				scanf("%d",&(Node1->data));

                Node1->next = s;
				p->next = Node1;
				p = p->next;
			}
		}
	}
}

void display(int n)
{
	int i=1;
	struct cll *p=s;
	printf("\n\nCircular linked list :\n");
	while(i<=n)
	{
		printf("\t%2d. %d\n",i++,p->data);
		p = p->next;
	}
}

int main()
{
	int n;
	printf("Number of nodes : ");
	scanf("%d",&n);
	create(n);
	display(2*n+2);
	return 0;
}
