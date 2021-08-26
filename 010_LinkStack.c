//Author Name: Pranoy Bhan
//Creation Date: 7 August 2021
//Purpose: Implementing a Stack using Linked List and develop functions to perform push and pop operations.

#include<stdio.h>	//Preprocessor directive to include standard input output header file
#include<stdlib.h>	//Preprocessor directive to include standard library header file

void push();	//Function Prototype
void pop();	//Function Prototype
void display();	//Function Prototype


struct node	// creating data type namely struct node
{
	int data;	//Member Variable
	struct node *next;	//Member Variable
};

typedef struct node Node;	// Using typedef function to change name from struct node to Node

Node *head=NULL;	// Creating a pointer namely head to store the address of first node


void main()	// main function
{
	int choice;
	
	while(1)	// menu 
	{
		printf("\n Select 1 for Push\n");
		printf("\n Select 2 for Pop\n");
		printf("\n Select 3 for Display\n");
		printf("\n Select 4 for Exit\n");
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
                    printf("\nImplementing push function\n");                           
                    push();
                    break;
            case 2:
                	printf("\nImplementing pop function\n"); 
                    pop();
                    break;
            case 3:
                    printf("\nImplementing display function\n");                           
                    display();
                    break;    
            
            case 4:
            		printf("Exiting the program!");
                    exit(0);
                    break;
            default:
                    printf("\nWrong Choice! :/");
                    break;
		}
	}
}

void push ()  // push function declaration
{  
    int num;  
    Node *pointer = (Node*)malloc(sizeof(Node));   // using malloc function for dynamically allocating memory
    if(pointer == NULL)  
    {  
        printf("No Space!");  // there is no space  
    }  
    else   
    {  
        printf("\nEnter the value: ");  
        scanf("%d",&num);  
        if(head==NULL)  
        {         
            pointer->data = num;  //pointer is pointing at data in node and assigining the value of num in data
            pointer -> next = NULL;  //pointer is pointing at next in node and assigining it NULL
            head=pointer; // storing the address of pointer in haed  
        }   
        else   
        {  
            pointer->data = num;  //pointer is storing the value of num in data
            pointer->next = head;  // pointer is storing the address of head in next
            head=pointer; // storing the address of pointer in head 
               
        }  
        printf("\nPushed\n");
		  
          
    }  
}  
  
void pop()  // pop function declaration
{  
    int store;  
    Node *pointer;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        store = head->data; // storing the value of data in store   
        pointer = head;  // storing the address of head in pointer
        head = head->next;  // moving head to next node
        free(pointer);  // freeing the space
        printf("\nPopped\n");  
        
          
    }  
}  
void display()  // display function declaration
{  
    int i;  
    Node *pointer;  
    pointer=head;  
    if(pointer == NULL)  
    {  
        printf("Empty\n");  
    }  
    else  
    {  
        printf("\nElements in Stacks are \n");  
        while(pointer!=NULL)  // using while loop to move pointer till we find NULL in node
        {  
            printf("%d\n",pointer->data); // accessing data in node to print its value 
            pointer = pointer->next;  // moving to next node
        }  
    }  
}  




