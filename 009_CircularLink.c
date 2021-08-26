//Author Name: Pranoy Bhan
//Creation Date: 8 August 2021
//Purpose: Implementing Circular Linklist 

#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;   
};  
typedef struct node Node;

Node *tail;  
      
void beginsert();   
void lastinsert();    
void begin_delete();  
void last_delete();   
void display();  
void search();  

void main ()  
{  
    int choice =0;  
    while(choice != 7)   
	{  
         
        printf("\nChoose one option from the following list ...\n");    
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.search\n6.display\n7.exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice) 
        {  
            case 1:  
                	beginsert();      
                	break;  
            
			case 2:  
                	lastinsert();         
                	break;  
            
			case 3:  
                	begin_delete();       
                	break;  
            
			case 4:  
                	last_delete();        
                	break;				 
            
			case 5:  
                	search();         
                	break;  
            
			case 6:  
                	display();        
                	break;  
            
			case 7:  
                	exit(0);  
                	break;  
            
			default:  
                	printf("Please enter valid choice..");  
        }  
    }  
}  

void beginsert()  
{  
    Node *ptr; 
    int item;   
    ptr = (Node *)malloc(sizeof( Node));
        
	printf("\nEnter the node: ");
	scanf("%d",&ptr -> data);
            
    ptr -> next = NULL; 
            
    if(tail == NULL)  
    {  
        tail = ptr;
        tail -> next = ptr;
    }  
    else   
    {  
        ptr -> next = tail -> next;
        tail -> next = ptr;
    }
}

void lastinsert()  
{  
    Node  *ptr; 
    int item;  
    ptr = ( Node *)malloc(sizeof( Node)); 
        
	printf("\nEnter Data"); 
	scanf("%d",&ptr -> data);
            
    ptr -> next = NULL;
    if(tail == NULL)
    {  
    	tail = ptr;
        tail -> next = ptr;
    }  
    else  
    {  
        ptr -> next = tail -> next;
        tail -> next = ptr;
        tail = ptr;
    }
}
      
void begin_delete()  
{  
    Node *temp;
	temp = tail -> next;   
    if(tail == NULL)  
    {  
        printf("\nList is Empty");    
    }  
    else if(temp == tail)  
    {  
        tail= NULL;  
        free(temp);  
        printf("\nnode deleted\n");  
    }  
          
    else  
    {   
        tail->next = temp->next;  
        free(temp);    
        printf("\nnode deleted\n");  
    }  
}  

void last_delete()  
{  
    Node *first, *last;  
    first = tail -> next;
        
	if(tail==NULL)  
    {  
        printf("\nList is Empty");  
    }  
    else if (first == tail)  
    {  
        tail = NULL;  
        free(first);  
        printf("\nnode deleted\n");  
    }  
    else   
    {  
		while(first ->next != tail -> next)  
        {  
            last = first;  
            first = first->next;  
        }  
        last->next = tail -> next; 
        tail = last;
		free(first);  
            
        printf("\nnode deleted\n");  
      
    }  
}

void search()  
{  
    Node *ptr;  
    int item,i=0,flag=1;  
    ptr = tail;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        if(tail ->data == item)  
        {  
        	printf("item found at location %d",i+1);  
            flag=0;  
        }  
                else  
                {  
                    flag=0;  
                }  
                i++;  
                ptr = ptr -> next;  
            }  
          
        if(flag != 0)  
        {  
            printf("Item not found\n");  
        }  
         
}  
      
void display()  
{  
    Node *ptr;  
    ptr=tail;  
    if(tail == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {  
        printf("\n printing values ... \n");  
              
        while(ptr -> next != tail)  
        {  
            printf("%d\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%d\n", ptr -> data);  
    }  
}  
