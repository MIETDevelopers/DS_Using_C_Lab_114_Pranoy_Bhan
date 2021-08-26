//Author Name: Pranoy Bhan
//Creation Date: 6 July 2021
//Purpose: Implementing a Priority Queue 

#include<stdio.h>
#include<stdlib.h>

int enqueue();
int dequeue();
int view();

int *alpha, front=-1, rear=-1, p, n, i, j;

int main()
{
	int choice, n;
	printf("\nEnter the size of Queue: ");
	scanf("%d",&n);
	
	alpha=  (int*)malloc(n*sizeof(int));
	
	while(1)
	{
		printf("\nPress 1 to Enqueue");
		printf("\nPress 2 to Dequeue");
		printf("\nPress 3 to View");
		printf("\nPress 4 to Exit");
		
		printf("\n\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue();
					break;
					
			case 2: dequeue();
					break;
					
			case 3: view();
					break;
					
			case 4: exit(0);
					break;
		}
	}
	return 0;
}

int enqueue() 
{
    if (rear == n -1) // goes MAx Size upto  // (n-1):Index Value  
        printf("\nQueue is in  overflow\n"); // 
    else
    {
        if(front == - 1) // Front is Emppty 
            front = 0; // Front =0 the rear incremennt
        printf("\nEnter the Desired element ");
        scanf("%d",&p);
        rear = rear + 1; // Rear=-1, 1st elemnt at 0th index 
        alpha[rear] = p; // Value store Ab 0th iNdex =KD 
    }
    return 0;
}

int box()
{
	
	for(i=0;i<=rear;i++)
	{
		if(p>=alpha[i])
		{
			for(j=rear+1;j>i;j--)
			{
				alpha[j]=alpha[j-1];
			}
			alpha[i]=p;
			return 0;
		}
	}
	alpha[i]=p;
	return 0;
}

int dequeue()
{
	if(front==-1 || front>rear)
	printf("\nQueue Underflow");
	
	else
	{
		printf("\nElement %d has been dequeued",alpha[rear]);
		rear=(rear-1);
	}
	return 0;
}

int view()
{
	int i;
	if(front==-1 || front>rear)
	{
		printf("\nBlank!");
	}
	else
	{
		printf("\nElements in Queue are: ");
		for(i=rear;i>=front;--i)
		{
			printf("%d",alpha[i]);
		}
	}
}
