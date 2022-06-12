#include <stdio.h>
#include <stdlib.h>

struct components
{
	char compo_name[30];
	char symbol;
	int value;
	float price;
};

void display(struct components arr[], int *size);
int create(struct components arr[]);
void modify(struct components arr[]);
int append(struct components arr[], int *size);
void search(struct components arr[], int *size);
void sort(struct components arr[], int *size);

int main()
{
	int choice, spec, nsize;
	struct components arr[10];

	do
	{
		printf("\n\tChose if want to perform operations on the Database of Electronic Components? , Yes(1)/No(0)");
		scanf("%d", &choice);
		if (choice == 1)
		{
			 
			printf("\nOperations on DATA BASE\n1:Create\n2:Display\n3:Modify\n4:Append\n5:Search\n6:Sort\n7:Exit\n");
			printf("\nValue=>");
			scanf("%d", &spec);

			switch (spec)
			{
			case 1:
			{
				nsize = create(arr);

				break;
			}
			case 2:
			{
				display(arr, &nsize);
				break;
			}
			case 3:
			{
				modify(arr);
				display(arr, &nsize);
				break;
			}
			case 4:
			{
				nsize = append(arr, &nsize);
				display(arr, &nsize);
				break;
			}
			case 5:
			{
				search(arr, &nsize);
				break;
			}
			case 6:
			{
				sort(arr, &nsize);
				display(arr,&nsize);
				break;
			}
			case 7:
				 {
					printf("\nExited from the program");
                    exit(0);
				 }
			default:
				printf("\nWrong input");
			}
		}
		else
		{
			continue;
		}
	} while (choice != 0);
	printf("\n\nDatabase Operations Completed\n\n");

	return 0;
}

int create(struct components arr[])
{
	int choice,size;
	size = 0;

	printf("\t\t\t\tx---------ELectronic Components---------x\n\n");

	printf("    ---------------------------------------------------------------------------------------------\n");
	printf("    |   Sr.No   |            Name of Component          |   Symbol  |    unit   |   cost(Rs.)   |\n");
	printf("    ---------------------------------------------------------------------------------------------\n");

	do
	{
		printf("\n\n\tAdd more components ?, Yes(1)/No(0) : ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("\n");
			printf("\nName of Component %d : ", size + 1);
			scanf("%s", &arr[size].compo_name);
			printf("\nSymbol of the component %d : ", size + 1);
			scanf("\t%c", &arr[size].symbol);
			printf("\nUnit of Component %d : ", size + 1);
			scanf("%d", &arr[size].value);
			printf("\nCost of Component %d : ", size + 1);
			scanf("%f", &arr[size].price);
			size++;
			display(arr, &size);
		}
		else
		{
			continue;
		}

	} while (choice != 0);
	return size;
}

void display(struct components arr[], int *size)
{
	printf("\nThe Component Table : \n\n");

	printf("    ---------------------------------------------------------------------------------------------\n");
	printf("    |   Sr.No   |Name of Component                      |   Symbol  |    unit   |   cost(Rs.)   |\n");
	printf("    ---------------------------------------------------------------------------------------------\n");

	for (int i = 0; i < *size; i++)
	{
		printf("    |     %d     |%-39s|     %c     |\t%d\t|    %3.2f\t|\n", i + 1, arr[i].compo_name, arr[i].symbol, arr[i].value, arr[i].price);
		printf("    ---------------------------------------------------------------------------------------------\n");
	}
}

void modify(struct components arr[])
{
	int no;
	printf("Enter the component number to modify it:");
	printf("\nValue=>");
	scanf("%d", &no);

	printf("\n");
	printf("\nName of Component %d : ", no);
	scanf("%s", &arr[no - 1].compo_name);
	printf("\nSymbol of the component %d : ", no);
	scanf("\t%c", &arr[no - 1].symbol);
	printf("\nUnit of Component %d : ", no);
	scanf("%d", &arr[no - 1].value);
	printf("\nCost of Component %d : ", no);
	scanf("%f", &arr[no - 1].price);
}

int append(struct components arr[], int *size)
{
	int no;
	no = *size;

	printf("\n");
	printf("\nName of Component %d : ", no + 1);
	scanf("%s", &arr[no].compo_name);
	printf("\nSymbol of the component %d : ", no + 1);
	scanf("\t%c", &arr[no].symbol);
	printf("\nUnit of Component %d : ", no + 1);
	scanf("%d", &arr[no].value);
	printf("\nCost of Component %d : ", no + 1);
	scanf("%f", &arr[no].price);

	return no + 1;
}

//linear search

void search(struct components arr[], int *size)

{
	int val, n,count;
	n = *size;
	count=0;

	printf("Enter the value of the component you want to search :");
	scanf("%d", &val);

	for (int i = 0; i < n; i++)
	{
		if (arr[i].value == val)
		{
			count+=1;
			printf("The Component has been Found in the DataBase at position: %d", i + 1);

			printf("\nThe Component at position %d is: \n\n", i + 1);

			printf("    ---------------------------------------------------------------------------------------------\n");
			printf("    |   Sr.No   |Name of Component                      |   Symbol  |    unit   |   cost(Rs.)   |\n");
			printf("    ---------------------------------------------------------------------------------------------\n");

			printf("    |     %d     |%-39s|     %c     |\t%d\t|    %3.2f\t|\n", i + 1, arr[i].compo_name, arr[i].symbol, arr[i].value, arr[i].price);
			printf("    ---------------------------------------------------------------------------------------------\n");

			break;
		}
	}
	if(count!=1)
	{
		printf("\nThe Component has been not Found in the DataBase\n");
	}
}

//bubble sort

void sort(struct components arr[], int *size)
{
   
    for (int j = 0; j <  *size - 1; j++)
    {
        for (int i = 0; i < *size- 1 - j; i++)
        {
            if ( arr[i].price > arr[i + 1].price)
            {
				float temp;
				temp=arr[i].price;
				arr[i].price=arr[i+1].price;
				arr[i+1].price=temp;
            }
        }
        printf("\n");   
    }
	 printf("\nAfter Sorting....................:");

}
