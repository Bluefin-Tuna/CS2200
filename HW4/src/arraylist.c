/**
 * Name: Tanush Chopra
 * GTID: 903785867
 */

/*  PART 2: A CS-2200 C implementation of the arraylist data structure.
    Implement an array list.
    The methods that are required are all described in the header file. Description for the methods can be found there.

    Hint 1: Review documentation/ man page for malloc, calloc, and realloc.
    Hint 2: Review how an arraylist works.
    Hint 3: You can use GDB if your implentation causes segmentation faults.
*/

#include "arraylist.h"

arraylist_t * create_arraylist(uint capacity) {
    arraylist_t * al = (arraylist_t *) malloc(sizeof(arraylist_t));
    if (!al) return 0;
    al -> backing_array = (char **) malloc(sizeof(char *) * capacity);
    if (!(al -> backing_array)) { free(al); return 0; }
    al -> size = 0;
    al -> capacity = capacity;
    return al;
}

void add_at_index(arraylist_t * al, char * d, int idx) {
    if (!d || idx < 0 || idx > al -> size) return;
    if (al -> size == al -> capacity) resize(al);
    for (int i = al -> size; i > idx; --i) al -> backing_array[i] = al -> backing_array[i - 1];
    al -> backing_array[idx] = d;
    al -> size++;
    return;
}

void append(arraylist_t * al, char * d) {
    if (!d || !al) return;
    add_at_index(al, d, al -> size);
    return;
}

char * remove_from_index(arraylist_t * al, int idx) {
    if (!al || idx < 0 || idx > al -> size) return 0;
    char * d = 0;
    if (idx == al -> size - 1) {
        d = al -> backing_array[idx];
        al -> backing_array[idx] = 0;
        al -> size--;
    } else {
        d = al -> backing_array[idx];
        al -> backing_array[idx] = 0;
        for (int i = idx; i < al -> size - 1; i++)
            al -> backing_array[i] = al -> backing_array[i + 1];
        al -> backing_array[al -> size - 1] = 0;
        al -> size--;
    }
    return d;
}

void resize(arraylist_t * al) {
    if (!al) return;
    char ** ral = (char **) realloc(al -> backing_array, sizeof(char *) * 2 * al -> capacity);
    if (!ral) return;
    al -> capacity = al -> capacity * 2;
    al -> backing_array = ral;
}

void destroy(arraylist_t * al) {
    if (!al) return;
    free(al -> backing_array);
}