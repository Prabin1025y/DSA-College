#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct STACK
{
    int TOS;
    float data[MAX];
};

void push(struct STACK *s, float element)
{
    if (s->TOS == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        s->data[++s->TOS] = element;
        printf("%.2f was pushed\n", s->data[s->TOS]);
    }
}

float pop(struct STACK *s)
{
    if (s->TOS == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        return s->data[s->TOS--];
    }
}

int main()
{
    struct STACK S = {-1};
    char exp[100];
    float op1, op2, result;

    printf("Enter the postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    if (exp[strlen(exp) - 1] == '\n')
        exp[strlen(exp) - 1] = '\0';
    printf("%s is a postfix expression\n", exp);

    char *token = strtok(exp, " ");
    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            push(&S, atof(token));
        }
        else
        {
            op2 = pop(&S);
            op1 = pop(&S);

            switch (token[0])
            {
            case '^':
                result = pow(op1, op2);
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            default:
                printf("Unknown operator: %s\n", token);
                return 1;
            }
            push(&S, result);
        }
        token = strtok(NULL, " ");
    }

    printf("Result = %.2f\n", pop(&S));
    return 0;
}