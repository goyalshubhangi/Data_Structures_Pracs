#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node* next;
}*s;

void createList(int n)
{
    struct node *Node1, *p;
    int data, i;

    s = (struct node*)malloc(sizeof(struct node));

    if(s == NULL)
    {
        printf("Memory not located");
    }
    else
    {
        printf("Enter the data at node 1: ");
        scanf("%d", &data);

        s->data = data; // Link data field with data
        s->next = NULL; // Link address field to NULL

        p = s;

        for(i=2; i<=n; i++)
        {
            Node1 = (struct node*)malloc(sizeof(struct node));
            if(Node1 == NULL)
            {
                printf("Memory not located");
                break;
            }
            else
            {
                printf("Enter the data at node %d: ", i);
                scanf("%d", &data);

                Node1->data = data; 
                Node1->next = NULL;
                p->next = Node1; 
                p = p->next; 
            }
        }

        printf("\tLINKED-LIST CREATED SUCCESSFULLY\n");
	}
}

void deleteAtBeginning()
{
	s=s->next;
}

bool deleteInMid(int x)
{
	bool found = false;
	if(s->data==x)
	{
		s=s->next;
		found=true;
	}
	else
	{
		for (struct node*p=s; p->next!=NULL; p=p->next)
		{
			if(p->next->data==x)
			{
				if(p->next->next!=NULL)
				{
					p->next=p->next->next;
					found=true;
					break;
				}
				else
				{
					p->next=NULL;
					found=true;
					break;
				}
			}
		}
	}
	return found;
}

void displayFull()
{
	struct node*p;
	if(s==NULL)
	{
		printf("\tEMPTY LIST!!!");
	}
	else
	{
		p = s;
		for(int i=1; p!=NULL; i++)
		{
			printf("%d. %d\n",i,p->data);
			p=p->next;
		}
	}
}

int main()
{
	int n, data, x;
	char choice;
	printf("Enter size of linked-list : ");
	scanf("%d",&n);
	createList(n);

	while(1)
	{
		printf("\n\n\tM  E  N  U\na. Delete the node at the beginning\nb. Delete the node after a specific value\nc. Display the linked-list : ");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a' :
			printf("\tDeleted data(%d) in the beginning!!\n",s->data);
			deleteAtBeginning();
			break;

			case 'b' :
			printf("\tEnter a number of the list : ");
			scanf("%d",&x);
			if(deleteInMid(x))
				printf("\tDeleted %d!!\n",x);
			else
				printf("\t%d not found in the list\n",x);
			break;

			case 'c' :
			displayFull();
			break;

			default :
			break;
		}
	}
	return 0;
}