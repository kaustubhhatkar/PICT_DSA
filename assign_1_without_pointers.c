#include <stdio.h>
#include <stdlib.h>

void CreateArray();
void DisplayArray();
void Insert();
void Delete();
void Modify();
void Search();
void Sort();

void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int A[50], i, a, num, pos, j, temp, sear, beg, end, mid, min;

int main()
{
    int val;
    do
    {
        printf("\n\n OPERATIONS ON ARRAY\n");
        printf("1] Create an Array\n");
        printf("2] Display the Array\n");
        printf("3] Insert an Element in the Array\n");
        printf("4] Delete an Element from the Array\n");
        printf("5] Modify a Element in the array\n");
        printf("6] Searching a Element in the array\n");
        printf("7] Sorting Elements in the array\n");
        printf("8] Exit\n");

        printf("Enter the number associated with the choice to perform that operation:");
        scanf("%d", &val);

        switch (val)
        {
        case 1:
            CreateArray();

            break;

        case 2:
            DisplayArray();
            break;
        case 3:
            Insert();
            break;

        case 4:
            Delete();
            a = a - 1;
            printArray(A, a);
            break;

        case 5:
            Modify();
            break;

        case 6:
            Search();
            break;

        case 7:
            Sort();
            break;

        case 8:
            printf("\nExited from the program");
            exit(0);

        default:
            printf("Your entered option is out of scope");
        }

    } while (val < 9);
    return 0;
}
//////functions starts
void CreateArray()
{

    printf("\nEnter the number of elements in the array you want:");
    scanf("%d", &a);
    printf("\n\tThe array is created\n");
    printf("Enter the values to add them in array\n");

    for (i = 0; i < a; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("\n!Array Created!\n");
}

void DisplayArray()
{

    printf("\nThe Values in the array are:\n");

    for (i = 0; i < a; i++)
    {
        printf("%p\t", A + i);
    }
    printf("\n");
    for (i = 0; i < a; i++)
    {
        printf("%d\t\t", i);
    }
    printf("\n");
    for (i = 0; i < a; i++)
    {
        printf("%d\t\t", A[i]);
    }
}

void Insert()
{

    printf("\nEnter the number you wish to Insert :");
    scanf("%d", &num);

    printf("\nEnter the index at which you want to insert the element:");
    scanf("%d", &pos);

    for (i = a; i >= pos; i--)
    {

        if (i == pos)
        {
            A[i + 1] = A[i];
            A[i] = num;
        }
        else
        {
            A[i + 1] = A[i];
        }
    }
    printf("\nIndex \tValue");
    for (i = 0; i < a + 1; i++)
    {
        printf("\n %d] \t%d ", i, A[i]);
    }
    printf("\n !Element inserted succesfully!");
    a = a + 1;
}

void Delete()
{

    printf("\nEnter the number you wish to Delete from the array :");
    scanf("%d", &num);

    for (i = 0; i < a; i++)
    {
        if (A[i] == num)
        {
            for (i; i < a; i++)
            {
                A[i] = A[i + 1];
            }
            A[i] = 0;
        }
        else
        {
            continue;
        }
    }
}

void Modify()
{

    printf("\nEnter the number you wish to modify in the array :");
    scanf("%d", &num);
    printf("\nEnter the number you want to replace :");
    scanf("%d", &j);

    for (i = 0; i <= a; i++)
    {
        if (A[i] == num)
        {

            A[i] = j;
        }
        else
        {
            continue;
        }
    }
    printf("\nIndex \tValue");
    for (i = 0; i < a; i++)
    {
        printf("\n% d] \t%d ", i, A[i]);
    }
    printf("\n !Element Modified succesfully!");
}

void Search()
{
    printf("\n1]Enter 1 If you want to use linear Search\n");
    printf("2]Enter 2 If you want to use Binary Search\n");
    printf("Number greater than 2 wont be accepted\n");
    printf("\n");

    scanf("%d", &sear);

    switch (sear)
    {
    case 1:
        printf("\n\n Enter the number you want to search in the array:");
        scanf("%d", &num);

        //Linear Search

        for (i = 0; i < a; i++)
        {
            if (A[i] == num)
            {
                printf("The number %d is at position %d", num, i);
            }
            else
            {
                continue;
            }
        }

        break;

    case 2:

        printf("\n\nFirst we need to sort the array in assending order\n");
        Sort();
        printf("\n\nNow You can Enter the number you want to search in the array:");
        scanf("%d", &num);

        beg = 0;
        end = a - 1;
        mid = (beg + end) / 2;
        while (beg <= end)
        {
            if (A[mid] < num)
                beg = mid + 1;
            else if (A[mid] == num)
            {
                printf("%d found at location %d", num, mid);
                break;
            }
            else
                end = mid - 1;
            mid = (beg + end) / 2;
        }
        if (beg > end)
        {
            printf("\nNot found.");
        }

        break;

    default:
        printf("Your entered option is out of scope");
    }
}

void Sort()
{
    int k;
    printf("\n1]Enter 1 If you want to use Bubble sort\n");
    printf("2]Enter 2 If you want to use Selection sort\n");
    printf("3]Enter 3 If you want to use insertion sort\n");
    printf("\n");
    scanf("%d", &sear);

    switch (sear)
    {
    case 1:
        printf("\n\n The array sorted in assending values is:\n");
        for (j = 0; j < a - 1; j++)
        {

            for (i = 0; i < a - 1 - j; i++)
            {
                if (A[i] > A[i + 1])
                {
                    temp = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = temp;
                }
            }

            printf("Pass %d\t", j);

            for (i = 0; i < a; i++)
            {
                printf("%d\t", A[i]);
            }
            printf("\n");
        }
        printf("\nThe Final Sorted Array is :");
        for (i = 0; i < a; i++)
        {
            printf("%d\t", A[i]);
        }

        break;

    case 2:
        printf("\n\n The array sorted in assending values is:");
        selectionSort(A,a);
        printArray(A, a);
        break;
    case 3:
        printf("\n\n The array sorted in assending values is:");
        insertionSort(A, a);
        printArray(A, a);
        break;

    default:
        printf("Your entered option is out of scope");
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
   
    for (i = 0; i < n-1; i++)
    {   
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    printf("\nIndex\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", i);\

    }
    printf("\nValue\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t ",A[i]);
    }
    printf("\n");

    printf("\n !Element Deleted succesfully!");
}