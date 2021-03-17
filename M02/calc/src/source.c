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

/* 
// Aalto's answer

void simple_multiply(void) {
    int a, b;
    int ret = scanf("%d %d", &a, &b);
    if(ret != 2) {
        return;
    }

    printf("%d * %d = %d\n", a, b, a*b);
}


void simple_math(void) {
    float a, b;
    char op;

    int ret = scanf("%f %c %f", &a, &op, &b);

    if(ret != 3) {
        printf("ERR\n");
        return;
    }

    switch(op) {
        case '+':
            printf("%.1f\n", a+b);
            break;
        case '-':
            printf("%.1f\n", a-b);
            break;
        case '/':
            printf("%.1f\n", a/b);
            break;
        case '*':
            printf("%.1f\n", a*b);
            break;
        default:
            printf("ERR\n");
            break;
    }
} */