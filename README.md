# ArrayList i C

Dette projekt implementerer en dynamisk arrayliste (`ArrayList`) i C, svarende til Java's `ArrayList`, men begrænset til `int` datatypen.

Testet på x86

## Funktioner

- `ArrayList* alst_create()`: Opretter en ny ArrayList.
- `void alst_add(ArrayList* list, int value)`: Tilføjer et element til ArrayList.
- `int alst_get(ArrayList* list, int index)`: Returnerer elementet ved et givent index.
- `int alst_size(ArrayList* list)`: Returnerer antallet af elementer i ArrayList.
- `void alst_remove(ArrayList* list)`: Fjerner det sidste element.
- `void alst_removeIndex(ArrayList* list, int index)`: Fjerner elementet ved et givent index.
- `void alst_insertIndex(ArrayList* list, int index, int value)`: Indsætter et element ved et givent index.
- `void alst_set(ArrayList* list, int index, int value)`: Overskriver elementet ved et givent index.
- `void alst_clear(ArrayList* list)`: Fjerner alle elementer fra ArrayList.
- `void alst_destroy(ArrayList* list)`: Frigør hukommelsen brugt af ArrayList.

## Eksempel på brug

```c
#include "arraylist.h"
#include <stdio.h>

int main() {
    ArrayList* list = alst_create();

    alst_add(list, 10);
    alst_add(list, 20);
    alst_add(list, 30);

    printf("Element på index 1: %d\n", alst_get(list, 1));  // Output: 20
    printf("Størrelse af listen: %d\n", alst_size(list));   // Output: 3

    alst_remove(list);
    printf("Efter fjernelse, størrelse: %d\n", alst_size(list));  // Output: 2

    alst_insertIndex(list, 1, 15);
    printf("Efter indsættelse på index 1: %d\n", alst_get(list, 1));  // Output: 15

    alst_destroy(list);
    return 0;
}
```
