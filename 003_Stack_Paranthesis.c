//Author: Pranoy Bhan
//Creation Date: 18 June 2021

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();

int ch, i, top = -1;
char p[20], b[20];
int main()
{
    while (1)
    {
        printf("Press 1 to check Expression\n");
        printf("Press 2 to exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:	printf("Enter expression\n");
            	scanf("%s", &b);
            	for (i = 0; b[i] != '\0'; i++)
            	{
                	if (b[i] == '(')
                	{
                    	push();
                	}
                else if (b[i] == ')')
                {
                    pop();
                }
            	}
            if (top == -1)
                printf("valid\n\n");
            else
                printf("not valid\n\n");
            	break;
        
		case 2:	exit(0);
            	break;
        
		default: printf("Wrong Choice");
        }
    }
}

void push()
{
    top++;
    p[top] = *b;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is Underflow ");
    }
    top--;
}
