// checking memory issues with valgrind using memcheck
// Here are only expose uninitilize memory and memory overwrites
// Compile: gcc -g valgrind_memcheck.c -o valgrind_memcheck
// -g flags generatesdebugging information
// Valgrind compile: valgrind --leak-check=full ./valgrind_memcheck

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main(int argc, char *argv[])
{
    int num1, num2;

    int *iArray = (int *) malloc(SIZE*sizeof(int));

    if(argc == 2)
    {
        num2 = atoi(argv[1]);
        printf("num2 values is: %d", num2);
    }

    // Forcing memory overwrites with a counter 1 element bigger than the reserved
    // memory for the iArray & assigning uninitilize memory.
    for(size_t i = 0; i <= SIZE; ++i)
    {
        iArray[i] = num1;
    }
    //
    for(size_t i = 0; i <= SIZE; ++i)
    {
        if(num2 == iArray[i])
        {
            num1 = i;
        }
    }
}
