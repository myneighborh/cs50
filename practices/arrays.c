#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check the command line argument
    if (argc != 2)
    {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    // Conver the argument from string to integer
    int size = atoi(argv[1]);

    // Validate that the size is a positive integer
    if (size <= 0)
    {
        printf("Please enter a positive integer.");
        return 1;
    }

    // Declare an array
    int numbers[size];
    numbers[0] = 1;

    // Populate an array
    for (int i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 2;
    }

    // Print out the values one by one
    for  (int i = 0; i < size; i++)
    {
        printf("%i\n", numbers[i]);
    }

    return 0;
}