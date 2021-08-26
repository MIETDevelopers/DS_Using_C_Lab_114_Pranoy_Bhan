//Author: Pranoy Bhan
//Creation Date : 5 June 2021
//Purpose : Implementing stacks using push, pop, view functions

#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void view();

int ch, stack[5], top=-1, i, p, b;

void main()
{
	while(1)
	{
		printf("\n Select 1 for Push\n");
		printf("\n Select 2 for Pop\n");
		printf("\n Select 3 for View\n");
		printf("\n Select 4 for Exit\n");
		printf("\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
			break;
			
			case 2: pop();
			break;
			
			case 3: view();
			break;
			
			case 4: exit(0);
			break;	
		}

	}
	
	}
void push()
{
	printf("\nEnter the value you want to push:\n");
		scanf("%d", &p);
		
	if(top==5-1)
	{
		printf("\nOverflow\n");
	}
	else
	{
		
		top++;
		
		stack[top]=p;
	}
}

void pop()
{
	if(top==-1)
		{
			printf("\nUnderflow\n");
		}
		else
		{
			b=stack[top];
			top--;
			
			printf("%d",b);
			
		}
}

void view()
{
	if (top==-1)
    {
        printf("Stack is empty!!!\n");
    }
    else
	{
	
		printf("Elements in Stack are: \n");
		
		for(i=top;i>=0;--i)
		{
			printf("%d\n",stack[i]);
		}
	}
}
