#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int i, stack[50], top = -1, n, op;
char expression[50];
void push()
{
    top++;
    stack[top] = n;
}
int pop()
{
    switch (op)
    {
    case 37:
        n = stack[top - 1] % stack[top];
        top = top - 2;
        break;
    case 42:
        n = stack[top - 1] * stack[top];
        top = top - 2;
        break;
    case 43:
        n = stack[top - 1] + stack[top];
        top = top - 2;
        break;
    case 45:
        n = stack[top - 1] - stack[top];
        top = top - 2;
        break;
    case 47:
        n = stack[top - 1] / stack[top];
        top = top - 2;
        break;
    case 94:
        n = pow(stack[top - 1], stack[top]);
        top = top - 2;
        break;
    default:
        printf("\nInvalid operator entered");
        exit(0);
        break;
    }
}
void main()
{
    printf("Name :Kaustubh Hatkar\t Roll no.:22129\n");
    printf("Operators and their operation: ");
    for (i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            printf("\n1: + : Addition");
        }
        else if (i == 1)
        {
            printf("\n2: - : Subtraction");
        }
        else if (i == 2)
        {
            printf("\n3: * : Multiplication");
        }
        else if (i == 3)
        {
            printf("\n4: / : Division");
        }
        else if (i == 4)
        {
            printf("\n5: ^ : Exponent");
        }
        else
        {
            printf("\n6: %c : Modulous", 37);
        }
    }
    printf("\n\nEnter a postfix expression (WITHOUT SPACE): ");
    gets(expression);
    for (i = 0; i < strlen(expression); i++)
    {
        if (isdigit(expression[i]) != 0)
        {
            n = expression[i] - 48;
            push();
        }
        else
        {
            op = expression[i];
            pop();
            push();
        }
    }
    printf("\nResult = %d", stack[0]);
}
