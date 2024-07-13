# Advanced Binary Search

## Description

The function searches for a value in a sorted array of integers using the Binary search algorithm.

-   Prototype: int advanced_binary(int \*array, size_t size, int value);
-   Where array is a pointer to the first element of the array to search in
-   size is the number of elements in array
-   And value is the value to search for
-   The function returns the index where value is located
-   If value is not present in array or if array is NULL, the function returns -1
-   Every time the value in the array is equal to the value we are searching for, the index of the value in the array is printed

## Usage

```c
int main(void)
{
    int array[] = {0, 1, 2, 5, 5, 6, 6, 7, 8, 9};
    int index;

    index = advanced_binary(array, 10, 5);
    printf("%d\n", index);
    return (0);
}
```

## Compilation

```bash
$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-advanced_binary.c -o advanced_binary
```
