#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(void)
{
    struct studentqueue q = {NULL, NULL};

    int go_on = 1;
    char buffer[100];
    while (go_on)
    {
        printf("Enter name of the student (\"-\" will end reading): ");
        scanf("%99s", buffer);
        buffer[99] = 0;
        if (strlen(buffer) > 0 && strcmp(buffer, "-"))
        {
            go_on = enqueue(&q, buffer);
        }
        else
        {
            go_on = 0;
        }
    }

    while (dequeue(&q, buffer, 100))
    {
        printf("Fetched %s from queue\n", buffer);
    }

    struct studentqueue *current = &q;
    while (current)
    { // Loop until a NULL pointer is reached
        printf("name: %s\n", current->name);
        current = current->next;
    }

    return 0;
}
