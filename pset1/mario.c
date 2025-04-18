#include <cs50.h>
#include <stdio.h>

#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

int get_height(void);
void print_pyramid(int height);

int main(void)
{
    int height = get_height();
    print_pyramid(height);
}

int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < MIN_HEIGHT || h > MAX_HEIGHT);
    return h;
}

void print_pyramid(int height)
{
    for (int row = 1; row <= height; row++)
    {
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}