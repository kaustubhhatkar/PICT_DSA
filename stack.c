#include<stdio.h>
#include<stdlib.h>

int stack[5];
int count_push=0;
int push();
int pop();

int main()
{
    int count,temp;

    printf("\t\t\t\t!Stack Implementation!");
    printf("\n\nNote:- Currently the Stack is Empty!,You need to Push the elements First.");

   do
   {
        printf("\n\nOperations in Stack to be performed:");
        printf("\n\n        1} Push");
        printf("\n        2} Pop");
        printf("\n        3} Exit");
        printf("\n\nEnter the number associated with the above operations to perform them:");
        scanf("%d",&count); 
    
        switch(count)
        {
            case 1:
                    {
                        push();
                        printf("Element Pushed Successfully");
                        break;
                    } 
            case 2: 
                    {
                        pop();
                        printf("Element Poped Successfully");
                        break;
                    }
            case 3:
                    {
                        printf("\nExited from program");
                        exit(0);
                    }   
        } 

    }
  
    while(count);
    return 0;
}

int push()
{
    int ans,ele;
    do
    {
        printf("\n\nDo you want to Push an element in the stack?");
        printf("\n(Type 1 For Yes) / (Type 0 For No) :"); 
        scanf("%d",&ans);
         
        if(ans==1)
        {   
            if(count_push<5)
            {
                printf("Enter the Element to push in the stack:");
                scanf("%d",&ele);
                stack[count_push]=ele;
                count_push+=1;

            }
            else
            {
                printf("You cannot Push any more elements in stack as it is Full!");
            }
        }
    
    }
    while(ans!=0);
}

int pop()
{
    int ans;
    do
    {
        printf("\n\nAre you sure you want to pop an element from the stack?");
        printf("\n(Type 1 For Yes) / (Type 0 For No) :");
        scanf("%d",&ans);
        if(ans==1)
        {
            if(count_push>=0)
            {
                
                printf("\nThe element %d is poped from the stack",stack[count_push-1]);
                count_push-=1;
                
            }
            else
            {
                printf("\n\nStack is Empty");
                break;
            }
               
        }
    }
    while(ans!=0);
}
