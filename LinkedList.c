#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node* next;
}*s;

void createList(int n)
{
    struct node *Node1, *p;
    int data, i;

    s = (struct node *)malloc(sizeof(struct node));

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

        printf("LINKED-LIST CREATED SUCCESSFULLY\n");
	}
}

void insertAtBeginning(int data)
{
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));

	if(p == NULL)
	{
		printf("Memory not located");
	}
	else
	{
		p->data = data;
		p->next = s;
		s = p;

		printf("DATA INSERTED SUCCESSFULLY\n");
	}
}

void insertAtEnding(int data)
{
	struct node*p=s,*Node2;
	Node2 = (struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("Memory not located");
	}
	else
	{
		Node2->data=data;
		Node2->next=NULL;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=Node2;
	}
}

bool insertInMid(int x, int data)
{
	struct node*p=s, *q;
	bool found = false;
	q=(struct node*)malloc(sizeof(struct node));
	for (; p->next!=NULL; p=p->next)
	{
		if(p->data==x)
		{
			q->next=p->next;
			p->next=q;
			q->data=data;
			found=true;
		}
	}
	return found;
}

void displayFull()
{
	struct node*p;
	if(s==NULL)
	{
		printf("EMPTY LIST");
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
		printf("\n\n\tM  E  N  U\na. Insert x at beginning\nb. Insert x at end\nc. Insert x in middle\nd. Display the linked-list : ");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a' :
			printf("Enter data to be put in the beginning : ");
			scanf("%d",&data);
			insertAtBeginning(data);
			printf("Inserted!!\n");
			break;

			case 'b' :
			printf("Enter data to be put in the beginning : ");
			scanf("%d",&data);
			insertAtEnding(data);
			printf("Inserted!!\n");
			break;

			case 'c' :
			printf("Enter a number of the list : ");
			scanf("%d",&x);
			printf("Enter data to be put after the first occurence of %d : ",x);
			scanf("%d",&data);
			if(insertInMid(x,data))
				printf("Inserted!!\n");
			else
				printf("%d not found\n",x);
			break;

			case 'd' :
			displayFull();
			break;

			default :
			break;
		}
	}
	return 0;
}
