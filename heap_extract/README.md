# Heap Extract

## Description

The function `heap_extract` extracts the root value of a Max Binary Heap.

## Prototype

```c
int heap_extract(heap_t **root);
```

## Usage

```c
int heap_extract(heap_t **root);
```

## Example

```c
#include <stdio.h>
#include "heap.h"

int main()
{
    heap_t *root = NULL;

    heap_insert(&root, 98);
    heap_insert(&root, 95);
    heap_insert(&root, 97);
    heap_insert(&root, 99);
    heap_insert(&root, 96);

    printf("Extracted: %d\n", heap_extract(&root));
    return (0);
}
```

## Author

**Kamran Khalilov**
