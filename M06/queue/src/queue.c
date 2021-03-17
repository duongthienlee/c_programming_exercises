#include "queue.h"
#include <stdlib.h> // for malloc
#include <string.h>
#include <stdio.h>

// Create an empty queue
struct studentqueue *createQueue()
{
    struct studentqueue *q = (struct studentqueue *)malloc(sizeof(struct studentqueue));
    if (q == NULL)
    {
        printf("Unable to allocate memory.");
        free(q);
    }
    q->name = NULL;
    q->next = NULL;
    return q;
}
/* 
 *  (a): Function int enqueue(struct studentqueue *q, const char *name) that adds given name as the last item of
 *  the list (that has NULL name in the beginning). The function makes two memory allocations: one for the data
 *  structure, and other for the name. The function returns value 1, if addition was successful, and value 0
 *  if it failed (for example because of failed memory allocation).
 */
int enqueue(struct studentqueue *q, const char *name)
{
    struct studentqueue *new = createQueue();
    new->name = malloc(strlen(name) + 1);
    if (new->name == NULL)
    {
        free(new);
        return 0;
    }
    strcpy(new->name, name); // allocated name
    new->next = NULL;        // set next pointer to NULL

    struct studentqueue *current = q;
    while (current)
    {
        if (current->next == NULL)
        {
            current->next = new;
            if (current->next == NULL)
            {
                free(current);
                return 0;
            }
            return 1;
            break;
        }

        current = current->next;
    }

    return 1;
}

/* 
 *  (b): Function int dequeue(struct studentqueue *q, char *buffer, unsigned int size) that removes the first item from the queue. 
 *  Before removing the item, the name it contains should be copied to address buffer. 
 *  In this address there is space for size characters, so you can copy at most size-1 characters. 
 *  You should also release the memory allocated for this item. The function returns value 1, 
 *  if there was an item removed from the list, and the related name is copied to buffer. 
 *  The function returns 0, if there was nothing removed from the list, for example because the list was already empty.
 */
int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
    if (q->next == NULL) // last node, nothing else to delete
        return 0;

    struct studentqueue *temp;
    temp = q->next;
    strncpy(buffer, temp->name, size);
    q->next = temp->next;
    free(temp->name);
    free(temp);

    return 1;
}

/* 
// Aalto's answer

int enqueue(struct studentqueue* q, const char* name) {
    while(q->next)
        q = q->next;

    q->next = malloc(sizeof(struct studentqueue));
    q->next->name = malloc(strlen(name) + 1);
    strcpy(q->next->name, name);
    q->next->next = NULL;

    return 1;
}

int dequeue(struct studentqueue* q, char* buffer, unsigned int size) {
    if(q->next == NULL)
        return 0;

    strncpy(buffer, q->next->name, size);
    buffer[size] = 0;

    struct studentqueue* del = q->next;
    q->next = q->next->next;

    free(del->name);
    free(del);

    return 1;
}
 */