//Author: Pranoy Bhan
//Creation Date: 27 June 2021
//Purpose: Implementing queue using enqueue and dequeue functions 

#include<stdio.h>
#include<stdlib.h>

int alpha[10];
int p, b, store, i, rear=-1, front=-1;

int enqueue();
int dequeue();
void view();

int main()
{
    printf("Enter size of Queue: ");
    scanf("%d",&p);
    
    while(1)
	{
        printf("\nPress 1 to Enqueue");
        printf("\nPress 2 to Dequeue");
        printf("\nPress 3 to View Elements");
        printf("\nPress 4 to Exit.");
        
		printf("\n\nYour choice: ");
        scanf("%d",&store);
        
		switch(store)
		{
            case 1:enqueue();
                   break;
            
			case 2:dequeue();
                   break;
            
			case 3:view();
                   break;
            
			case 4:exit(0);
            
        }
    }
    return 0;
}

int enqueue()
{
    if (rear==p-1)
        printf("\nOverflow\n");
    else
    {
        if(front==-1)
        front = 0;
        
		printf("\nEnter Element: ");
        scanf("%d",&b);
        
		rear=rear+1;
        alpha[rear]=b;
    }
    return 0;
}

int dequeue()
{
    if(front==-1 && rear==-1)
        printf("\nUnderflow\n");
    else
    {
        printf("\nElement %d has been dequeued\n",alpha[front]);
        front=front+1;
    }
    return 0;
}

void view()
{
    if (front ==-1)
	{
        printf("\nBlank!");
    }
    else
	{
        printf("\nElements in Queue:\n");
        for(i=front; i<=rear; ++i)
		{
            printf("%d\n",alpha[i]);
        }
    }
}
