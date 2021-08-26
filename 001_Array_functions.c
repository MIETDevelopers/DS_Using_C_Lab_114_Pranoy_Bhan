//Author: Pranoy Bhan
//Creation Date : 25 May 2021
//Purpose : Inserting, deleting and searching an Element in an array
           
#include<stdio.h>
#include<stdlib.h>

void insert();
int search();
int deletee();

int a[10], choice, i, n;

int main()
{
    printf("Enter the size in an array: ");
    scanf("%d",&n);
    printf("\nEnter %d elements in an array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
	{
        printf("\nEnter 1 to insert element in array.");
        printf("\nEnter 2 to search element in array.");
        printf("\nEnter 3 to Delete element in array.");
        printf("\nEnter 4 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
		{
            case 1:insert(a);
                        break;
          	case 2:search(a);
                        break;
            case 3:deletee(a);
                        break;
            case 4:exit(0);
        }
    }
    return 0;
}

void insert()
{
    int l,x;
    
	printf("\n enter location where elements is to be inserted: ");
    scanf("%d",&l);
    printf("\n enter element to be inserted: ");
    scanf("%d",&x);
    n=n+1;
    for(i=n-1;i>=l;i--)
    {
        a[i]=a[i-1];
    }

    a[i]=x;
    printf("\nArray After insertion is: ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    a[i]='\0';
    }

int search()
{
    int j;
    printf("Enter element to search: "); 
    scanf("%d",&j);
     
    for(i=0;i<n;++i)
        if(a[i]==j)
            break;
     
if(i<n){
        printf("Element %d found at index %d", j, i);
    }     
    else{
        printf("Element not found"); 
    }
    return 0;
}

int deletee()
{
    int c,posi;
    for(i=0;a[i]!=NULL;i++)
    {
    }
    printf("\nEnter the position to delete element: ");
    scanf("%d",&posi);
    if(posi<=i)
    {
        for(c=posi-1;c<i-1;c++)
        {
            a[c]=a[c+1];
        }
        printf("\nArray after Deletion");
        for(c=0;c<i-1;c++)
        {
            printf("\n%d",a[c]);
        }
    }
    a[c]='\0';
	return 0;
}
