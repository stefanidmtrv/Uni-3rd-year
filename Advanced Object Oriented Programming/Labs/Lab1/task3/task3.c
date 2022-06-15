#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        return 0;
    }
    else
    {
        int num = atoi(argv[1]);
        int result = fibonacci(num);
        printf("Fibonacci of %d = %d\n", num, result);
        return 0;
    }
}

// task 2 
// gcc task2.c fibonacci.c -o task2
// ./task2

// task 3
// gcc -c fibonacci.c -o fibonacci.o
// gcc task3.c fibonacci.c -o task3
// ./task3