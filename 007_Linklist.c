//Author: Pranoy Bhan
//Creation Date : 27 July 2021

#include<stdio.h>  
#include<stdlib.h>   

struct node   

{  
    int data;  
    struct node *next;   
};  

typedef struct node Node;

Node *head;  
  
void insert_beginning();  
void insert_specific();  
void delete_specific();  
void search();  
void display();

void main()  
{  
    int choice; 
    
    while(1)   
    {  
		     
        printf("\n1.Insert in Beginning");
		printf("\n2.Insert at Specified Position");
		printf("\n3.Delete from a Specific Position");
		printf("\n4.Display");
		printf("\n5.Search ");
		printf("\n6.Exit From Program"); 
        
		printf("\n\nYour choice: ");         
        scanf("\n%d",&choice);  
        
		switch(choice)  
        {  
            case 1: insert_beginning(); 
            		break;  
            
			case 2: insert_specific();      
            		break;
					  
			case 3:	delete_specific();          
            		break;
					  
            case 4: display();        
            		break;
					  
            case 5: search();        
            		break;
					  
            case 6: exit(0);  
            		break;  
            
			default: printf("Please enter a valid choice..");  
        }  
    }  
}  

void insert_beginning()
{  
    Node *pointer;  
    int item;  
    
	pointer = (Node *) malloc(sizeof(Node *));  
    if(pointer == NULL)  
    {  
        printf("\nNo Space");  
    }  
    else  
    {  
        printf("\nEnter value: ");    
        scanf("%d",&item);    
        
		pointer->data = item;      
        pointer->next = head;  
        head = pointer;  
        
		printf("\n Node inserted successfully\n");
		printf("\n%d is added in the List",item)  ;
    }  
      
}  

void insert_specific()  
{  
    int i,location,item;   
    
	Node *pointer, *tent;  
    pointer = (Node *) malloc (sizeof(Node));  
    if(pointer == NULL)  
    {  
        printf("\nNo Space!");  
    }  
    else  
    {  
        printf("\nEnter element value: ");  
        scanf("%d",&item);  
        
		pointer->data = item;  
        printf("\nEnter the location at which you want to insert: ");  
        scanf("\n%d",&location);  
        
		tent=head;  
        
		for(i=0;i<location;i++)  
        {  
            tent = tent->next;  
            if(tent == NULL)  
            {  
                printf("\ncan't insert\n");   
            }  
          
        }  
        pointer ->next = tent ->next;   
        tent ->next = pointer;   
        printf("\nNode inserted");  
    }  
}  
void delete_specific()  
{  
    Node *pointer,*pointer1;  
    
	int location,i;    
    
	printf("\n Enter the location at which you want to perform deletion: ");  
    scanf("%d",&location);  
    
	pointer=head;  
    
	for(i=0;i<location;i++)  
    {  
        pointer1 = pointer;       
        pointer = pointer->next;  
              
        if(pointer == NULL)  
        {  
            printf("\nCan't delete");    
        }  
    }  
    pointer1 ->next = pointer ->next;  
    free(pointer);  
    printf("\nDeleted node %d ",location+1);  
}  

void search()  
{  
	int item, i, alpha;
    Node *pointer;
    pointer = head;   
    
	if(pointer == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
           for( i=0;pointer!=NULL;i++)  
        {  
            if(pointer->data == item)  
            {  
                printf("item found at location %d\n",i+1);  
                alpha=0;  
                if (alpha==0)
                {
                    break;
                }
                
            }   
            else  
            {  
                alpha=1;  
            }  
             
            pointer = pointer -> next; 
            if(pointer==NULL)
			{ 
        		if(alpha==1)  
        		{  
            		printf("Item not found\n");  
        		}  
        	}  
        }
    }     
          
}
  
void display()  
{  
    Node *pointer;  
    pointer = head;   
    
	if(pointer == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nElements are: \n");   
        while (pointer!=NULL)  
        {  
            printf("\n%d",pointer->data);  
            pointer = pointer -> next;  
        }  
    }  
}     
