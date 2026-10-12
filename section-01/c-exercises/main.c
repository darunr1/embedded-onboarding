#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void FizzBuzz(int n) 
{
    if (n % 15 == 0) 
    {
        printf("FizzBuzz\n");
    } 
    else if (n % 3 == 0) 
    {
        printf("Fizz\n");
    } 
    else if (n % 5 == 0)
    {
        printf("Buzz\n");
    }
}


int compare_desc(const void *a, const void *b) 
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (y > x) - (y < x);
}


int main(void) 
{
    printf("Hello, World!\n");

    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);

    int *numbers = malloc(20 * sizeof(int));

    if (numbers == NULL) 
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 20; i++) 
    {
        *(numbers + i) = i + 1;
    }

    printf("\nFizzBuzz for array 1-20:\n");

    for (int i = 0; i < 20; i++) 
    {
        FizzBuzz(*(numbers + i));
    }

    printf("\nFizzBuzz for numbers 1-30:\n");

    for (int i = 1; i <= 30; i++) 
    {
        FizzBuzz(i);
    }
    
    qsort(numbers, 20, sizeof(int), compare_desc);

    printf("\nSorted array in descending order:\n");

    for (int i = 0; i < 20; i++) 
    {
        printf("%d ", *(numbers + i));
    }

    printf("\n");

    free(numbers);

    return 0;
}
