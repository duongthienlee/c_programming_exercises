#include "source.h"

#include <stdio.h>
#include <math.h>

void simple_multiply(void)
{
    int a, b;

    scanf("%d", &a);
    scanf("%d+\n", &b);

    printf("%d * %d = %d\n", a, b, a * b);
}

void simple_math(void)
{
    float a, b;
    char operator;

    scanf("%f", &a);
    scanf(" %c ", &operator);
    scanf("%f+\n", &b);

    switch (operator)
    {
    case '+':
        printf("%.1f\n", a + b);
        break;
    case '-':
        printf("%.1f\n", a - b);
        break;
    case '*':
        printf("%.1f\n", a * b);
        break;
    case '/':
        printf("%.1f\n", a / b);
        break;
    default:
        printf("ERR\n");
        break;
    }
}
