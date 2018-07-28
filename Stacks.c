#include<stdio.h>
#include<stdbool.h>

int main()
{
	int size=50, choice = 0, top=0;
	printf("Enter size of stack you want : ");
	scanf("%d",&size);
	int stack[size];
	for (int i = 0; i < size; ++i)
	{
		stack[i]=0;
	}

	bool exit = false;

	while(!exit)
	{
		for (int i = 0; i < 100; ++i)
		{
			printf("-");
		}
		printf("\n\tChoose your option :\n\n1.Push\n\n2.Pop\n\n3.Display All\n\n Any other key to Exit\t:  ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 :
				if(top==size)
					printf("\tThe stack is FULL\n");
				else
				{
					printf("\tEnter a number you want to enter in the stack : ");
					scanf("%d",&stack[top++]);
					printf("\tStack updated!!\n");
				}
				break;

			case 2 :
				printf("\t%s%d\n", "The number over the top is : ", stack[--top]);
				break;

			case 3 :
				if(top!=0)
				{
					printf("\n\tThe stack is :\n");
					for (int i = 0; i < top; ++i)
					{
						printf("\t  %2d. %d\n", i+1, stack[i]);
					}
				}
				else
					printf("The stack is EMPTY\n");
				break;

			default :
				exit = true;
		}
	}
}