#include <cs50.h>
#include <stdio.h>

void print_row(int bricks, int total_height);

int main(void)
{
    // Prompt user for input
    int height;
    do
    {
        height = get_int("What is the height of pyramid?");
    }
    while (height < 1 || height > 8);
    
    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        print_row(i + 1, height);
    }
}

void print_row(int bricks, int total_height)
{
    // Print spaces
    for (int i = 0; i < total_height - bricks; i++)
    {
        printf(" ");
    }

    // Print left hashes
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    // Print gap
    printf("  ");

    // Print right hashes
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    printf("\n");
}