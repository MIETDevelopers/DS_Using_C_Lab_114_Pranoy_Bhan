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
     Node *tail = NULL;  
      
void beginsert ();   
void lastinsert (); 
void begin_delete();  
void last_delete();   
void display();  
void search();  
    void main ()  
    {  
        int choice =0;  
        while(choice != 7)   
        {  
            printf("\n*********Main Menu*********\n");  
            printf("\nChoose one option from the following list ...\n");  
            printf("\n===============================================\n");  
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
        
		 printf("\nEnter the node data");
		   
            scanf("%d",&ptr -> data); /* taking input from Node data*/
            
            ptr -> next = NULL; /* Node is not pointing to anyone */
            
        if(tail == NULL) 
        {  
            tail = ptr;
            tail -> next = ptr; /* Inserted 1st node when list is Empty*/
        }  
        else   
        {  /*we are using else condition when list is not empty*/
            ptr -> next = tail -> next; /* linking nodes*/
            tail -> next = ptr; /* inserted node successfully*/
        }
    }
    void lastinsert()  
    {  
        Node  *ptr; 
        int item;  
        ptr = ( Node *)malloc(sizeof( Node)); 
        
		printf("\nEnter Data"); 
		 
        scanf("%d",&ptr -> data);
            
            ptr -> next = NULL; /* Node is not pointing to anyone(NODE created).*/
            
        if(tail == NULL)
        {  /* list is not empty but there is only one Node*/
        tail = ptr;
        
        tail -> next = ptr;
        }  
        else  
        {  /* when there are multiple Nodes in the list*/
          ptr -> next = tail -> next;
          tail -> next = ptr;
          tail = ptr;
      }
  }
      
    void begin_delete()  
    {  
         Node *temp;
		 temp = tail -> next;   /* getting Address of 1st Node by tail -> next
		  as it is always going to store address f 1st Node.*/
		 
        if(tail == NULL)  
        {  
            printf("\nList is Empty");    
        }  
        else if(temp == tail)  /* if list is not empty but we have only one 
     Node in the list. */
        { 
            tail= NULL;  /* AS it is only one NODE in the list so we have to break 
            the link between temp and tail(as they both are ponting to same NODE)
		so 	as to delete the  NODE */
            
            free(temp);  
            printf("\nnode deleted\n");  
        }  
          
        else  
        {   // when there are multiple nodes in the list.
            tail->next = temp->next;  /* temp -> next is pointing to first node 
            and by tail -> next = temp -> next we are linking tail to 1st NODE */ 
            free(temp);  /* NOW first NODE is deleted as temp is pointing to 1st
		NODE but we also have to free this memory now tail will point to next
		NODE and in this way 1st Node is deleted*/ 
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
        {  /* There is only one Node in the list*/
            tail = NULL;  
            free(first);  
            printf("\nnode deleted\n");  
      
        }  
        else   
        {  

        while(first ->next != tail -> next) /* if first -> next!= tail -> next
			then there are multiple NODES in the list*/ 
			 
            {  //  traversing the list
                last = first;  
                
               first = first->next;  /* MOVING the first*/
            }  
            last->next = tail -> next;  /* linking last and tail */
            
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
            while (ptr->next != tail)  
            {  
                if(ptr->data == item)  
                {  
                    printf("item found at location %d ",i+1);  
                    flag=0;  
                    break;  
                }   
                else  
                {  
                    flag=1;  
                }  
                i++;  
                ptr = ptr -> next;  
            }  
            }  
            if(flag != 0)  
            {  
                printf("Item not found\n");  
            }  
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
