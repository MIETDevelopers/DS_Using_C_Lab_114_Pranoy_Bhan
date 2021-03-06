//Author Name: Pranoy Bhan
//Creation Date: 8 August 2021
//Purpose: Implementing a Doubly Linked List

#include<stdio.h>  
#include<stdlib.h>  
    struct node  
    {  
        int data;
        struct node *prev;  
        struct node *next;  
         
    };  
    typedef struct node Node;
     Node *head,*tail;
    void insertion_beginning();  
    void insertion_last();  
    void insertion_specified();  
    void deletion_beginning();  
    void deletion_last();      
    void deletion_specified();  
    void display();  
    void search();
	void create(); 
    void main ()  
    {  
    int choice =0;  
        while(choice != 10)  
        {  
            printf("\n*********Main Menu*********\n");  
            printf("\nChoose one option from the following list ...\n");  
            printf("\n===============================================\n");  
            printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n");  
           printf(" 5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.CREATE NODE\n10.EXIT\n");  
            printf("\nEnter your choice:    \n");  
            scanf("\n%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                insertion_beginning();  
                break;  
                
                case 2:  
                    insertion_last();  
                break;  
                case 3:  
                insertion_specified();  
                break;  
                case 4:  
                deletion_beginning();  
                break;  
                case 5:  
                deletion_last();  
                break;  
                case 6:  
                deletion_specified();  
                break;  
                case 7:  
                search();  
                break;  
                case 8:  
                display();  
                break; 
				case 9:
				create();
				break; 
                case 10:  
                exit(0);  
                break;  
                default:  
                printf("Please enter valid choice..");  
            }  
        
    }
}
void create(){
	int choice_user;
	Node *ptr,*temp;
	head = 0;
	
	
	ptr = (Node*) malloc(sizeof(Node));
	
	printf("Enter data");
	
	scanf("%d",&ptr -> data);
	
	ptr -> prev = 0;
	ptr -> next = 0;
	
	if ( head == 0){
		head = temp;
	}
	else {
		temp -> next = ptr;
		ptr -> prev = temp;
		temp = ptr;
	}

}

    void insertion_beginning()  
    {  
        Node *ptr;
		int item;  
    ptr = (Node *)malloc(sizeof(Node));  
       printf("Enter data :    ");
       scanf("%d",&ptr -> data);
       ptr -> prev = 0;
       ptr -> next = 0;
       head -> prev = ptr;
       ptr -> next = head;
       head = ptr;
   
       printf("\n Node inserted");
}

   
         
    
   void insertion_last()

{

    Node *ptr;

    int d;

    ptr = (Node *)malloc(sizeof(Node));

    if (ptr == NULL)

    {

        printf("List is empty");

    }

    else
	{


        printf("Enter data which you want to insert\n :   ");

        scanf("%d", &d);
        ptr -> data = d;

        ptr->prev = NULL;

        ptr->next = NULL;


        tail->next = ptr;

        ptr->prev = tail;
        
         tail = ptr;

    }
}


    void insertion_specified()  
    {  
         
       int pos,i = 1;  
       
       if ( pos == 1){
       	printf(" kindly proceed to insert at begining");
	   }
       
       else 
       {  
       Node *ptr,*temp;
	   temp = head;
       
        ptr = ( Node *)malloc(sizeof(Node));
        
           printf("Enter the data"); 
		    
           scanf("%d",&ptr -> data); 
		    
          while ( i < pos-1){
          	temp = temp -> next;
          	i++;
		  }
		  ptr -> prev = temp;
		  ptr -> next = temp -> next;
		  temp -> next = ptr;
		  ptr -> next -> prev = ptr;
	}
           
       }  
      
    void deletion_beginning()  
    {  
         Node *temp;  
        if(head == 0)  
        {  
            printf("\n No node in the list");  
        }  
       
        else  
        {  
            temp = head;  
            head = head -> next;  
            head -> prev = 0;  
            free(temp);  
            printf("\nnode deleted\n");  
        }  
      
    }  
    void deletion_last()  
    {  
         Node *temp;  
        if(head == 0)  
        {  
            printf("\n List is Empty");  
        }  
        
        else   
        {  
            temp = tail;   
           
            tail -> prev -> next = 0;
            
             tail = tail -> prev;
             
            free(temp);
            
            printf("\nnode deleted\n");  
        }  
    }  
    void deletion_specified()  
    {  
         Node  *temp;
		 temp = head; 
         
		 int pos,i = 1;
		  
        if(pos == 1){
        	
        	printf(" kindly go to delete at first Node");
		}
		printf("Enter the position");
		
		scanf("%d",&pos);
		
		while( i < pos){
			temp = temp -> next;
			i++;
		
		}
		temp -> prev -> next = temp -> next;
		free(temp);
            printf("\nnode deleted\n");  
        }     
     
    void display()  
    {  
         Node *ptr;  
        printf("\n printing values...\n");  
        ptr = head;  
        while(ptr != NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr=ptr->next;  
        }  
    }   
    void search()  
    {  
         Node *ptr;  
        int item,i=0,flag;  
        ptr = head;   
        if(ptr == NULL)  
        {  
            printf("\nEmpty List\n");  
        }  
        else  
        {   
            printf("\nEnter item which you want to search?\n");   
            scanf("%d",&item);  
            while (ptr!=NULL)  
            {  
                if(ptr->data == item)  
                {  
                    printf("\nitem found at location %d ",i+1);  
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
            if(flag==1)  
            {  
                printf("\nItem not found\n");  
            }  
        }     
              
    }  
