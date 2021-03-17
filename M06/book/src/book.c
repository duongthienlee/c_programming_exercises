#include "book.h"
#include <stdlib.h>  // for malloc
#include <stdio.h>
#include <string.h>

int init_book(struct book *p_book, const char *p_id, const char *p_title, const char * p_author, struct date release)
{
    if(strlen(p_id) > 9) return 0;
    else memmove(p_book->id, p_id, sizeof(char) * strlen(p_id) + 1);

    // allocated p_title
    p_book->title = malloc(strlen(p_title) + 1);
    if (p_book->title == NULL) {
        free(p_book);  // because it was already allocated
        return 0;
    }
    strcpy(p_book->title, p_title);

    // allocated p_author
    p_book->author = malloc(strlen(p_author) + 1);
    if (p_book->author == NULL) {
        free(p_book);  // because it was already allocated
        return 0;
    }
    strcpy(p_book->author, p_author);

    p_book->release_date = release;

    return 1;
}

struct book *add_to_collection(struct book *collection, unsigned int size, struct book new_book)
{
    // Increase size of the array by one, and reserve space for final NULL member
    struct book *newarray = realloc(collection, sizeof(struct book) * (size + 2));
    if (newarray == NULL) return NULL; // allocating memory did not work
    
    init_book(&new_book, new_book.id, new_book.title, new_book.author, new_book.release_date);

    newarray[size] = new_book;
    return newarray;
}


/* 
// Aalto's answer

int init_book(struct book* p_book, const char* p_id, const char* p_title, const char* p_author, struct date release) {
	if(strlen(p_id) > 9)
        return 0;

    p_book->title = malloc(strlen(p_title) + 1);
    p_book->author = malloc(strlen(p_author) + 1);
    strcpy(p_book->title, p_title);
    strcpy(p_book->author, p_author);
    strcpy(p_book->id, p_id);
    p_book->release_date = release;

    return 1;
}

struct book* add_to_collection(struct book* collection, unsigned int size, struct book new_book) {
    collection = realloc(collection, (size + 1) * sizeof(struct book));

    int ret = init_book(&collection[size], new_book.id, new_book.title, new_book.author, new_book.release_date);
    if(ret == 0) {
        printf("Too long id provided!");
        free(collection);
        return NULL;
    }

    return collection;
}
*/