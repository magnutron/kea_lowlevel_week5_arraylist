#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

#define INITIAL_CAPACITY 10

// Hjælpefunktion til at udvide kapaciteten
static void resize(ArrayList* list, int new_capacity) {
    int* new_data = (int*) malloc(new_capacity * sizeof(int));
    if (!new_data) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(new_data, list->data, list->size * sizeof(int));
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

// Opretter en ny ArrayList
ArrayList* alst_create() {
    ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    list->data = (int*) malloc(INITIAL_CAPACITY * sizeof(int));
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    return list;
}

// Tilføjer et element til ArrayList
void alst_add(ArrayList* list, int value) {
    if (list->size == list->capacity) {
        resize(list, list->capacity * 2);  // Fordobler kapaciteten
    }
    list->data[list->size++] = value;
}

// Returnerer elementet ved et givent index
int alst_get(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    return list->data[index];
}

// Returnerer størrelsen af ArrayList
int alst_size(ArrayList* list) {
    return list->size;
}

// Fjerner det sidste element fra ArrayList
void alst_remove(ArrayList* list) {
    if (list->size > 0) {
        list->size--;
        if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
            resize(list, list->capacity / 2);  // Formindsker kapaciteten
        }
    }
}

// Fjerner elementet ved et givent index
void alst_removeIndex(ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(int));
    list->size--;
    if (list->size < list->capacity / 2 && list->capacity > INITIAL_CAPACITY) {
        resize(list, list->capacity / 2);
    }
}

// Indsætter et element på et givent index
void alst_insertIndex(ArrayList* list, int index, int value) {
    if (index < 0 || index > list->size) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    if (list->size == list->capacity) {
        resize(list, list->capacity * 2);
    }
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(int));
    list->data[index] = value;
    list->size++;
}

// Overskriver elementet ved et givent index
void alst_set(ArrayList* list, int index, int value) {
    if (index < 0 || index >= list->size) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    list->data[index] = value;
}

// Fjerner alle elementer fra ArrayList
void alst_clear(ArrayList* list) {
    list->size = 0;
    resize(list, INITIAL_CAPACITY);  // Sætter kapaciteten tilbage til initial størrelse
}

// Frigør hukommelsen brugt af ArrayList
void alst_destroy(ArrayList* list) {
    free(list->data);
    free(list);
}
