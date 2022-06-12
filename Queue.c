#include<stdio.h>
#define size 5
struct queue
{
	int front,rear,a[size];
}q;

void create();
void enqueue(int);
int dequeue();
int fullq(struct queue);
int emptyq(struct queue);
void display();

void main()
{
	int choice,num,key;
    printf("Queue Operations!");
	do
	{
	printf("\nSelect the operation");
	printf("\n  1.Enqueue\n  2.Dequeue\n  3.isempty\n  4.isfull\n=> ");
	scanf("%d",&choice);
	
	switch(choice)
	{
	    case 1:if(fullq(q))
				{
					printf("\nQueue Overflow");
	        	}
				else
	            {
					enqueue(num);
	            }
				break;    
		case 2: if(emptyq(q) || q.front>q.rear)
				   {
				   	printf("\nEmpty Queue");
				   }
				   else
				   {
				   	key=dequeue();
				   	printf("\nDequeue element is: %d",key);
				   }
				   break;
		case 3:if(emptyq(q) || q.front>q.rear)
				{
					printf("\nQueue is empty!!!");	
				}
				else
				{
					printf("\nQueue is not empty!!!");
				}
				break;
		case 4:if(fullq(q))
				{
					printf("\nQueue is full!!!");
				}
				else
				{
					printf("\nQueue is not full!!!");
				}
				break;
		default:printf("\nPlease select the proper operation");        
	}
 }while(choice!=0);
		
}


int emptyq(struct queue q)
{
	if(q.front==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int fullq(struct queue q)
{
	if(q.rear>=size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(int num)
{
	printf("\nEnter queue element:-");
	scanf("%d",&num);
	if(emptyq(q))
	{
		q.front=0;
	}
	q.rear++;
	q.a[q.rear]=num;
}

int dequeue()
{

	int x,i;
	x=q.a[q.front];
	for(i=q.front;i<q.rear;i++)
	{
		q.a[i]=q.a[i+1];
	}
	q.rear--;
	return x;
}


