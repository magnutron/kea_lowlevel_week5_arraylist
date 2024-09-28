#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
    int *data;      // Pointer til hvor listen gemmer sine data
    int capacity;   // Den totale kapacitet
    int size;       // Antallet af brugte elementer
} ArrayList;

// Constructor til at oprette en ny ArrayList
ArrayList* alst_create();

// Funktioner til at manipulere ArrayList
void alst_add(ArrayList* list, int value);
int alst_get(ArrayList* list, int index);
int alst_size(ArrayList* list);
void alst_remove(ArrayList* list);
void alst_removeIndex(ArrayList* list, int index);
void alst_insertIndex(ArrayList* list, int index, int value);
void alst_set(ArrayList* list, int index, int value);
void alst_clear(ArrayList* list);

// Funktion til at frigøre den allokerede hukommelse
void alst_destroy(ArrayList* list);

#endif // ARRAYLIST_H
