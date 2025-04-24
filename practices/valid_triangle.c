#include <stdio.h>
#include <stdbool.h>

bool check_valid_triangle(float x, float y, float z);

int main(void)
{
    float a, b, c;
    printf("first number: ");
    scanf("%f", &a);

    printf("second number: ");
    scanf("%f", &b);

    printf("third number: ");
    scanf("%f", &c);

    if (check_valid_triangle(a, b, c))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

bool check_valid_triangle(float x, float y, float z)
{
    // check for all positive sides
    if (x < 0 || y < 0 || z < 0)
    {
        return false;
    }

    // check that sum of any two sides greater than third
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }

    return true;
}