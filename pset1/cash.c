#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_coins(int cents);


int main(void)
{
    int cents = get_cents();
    int coins = calculate_coins(cents);
    printf("%d\n", coins);
}

int get_cents(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    return round(dollars * 100);
}

int calculate_coins(int cents)
{
    int coins = 0;
    coins += cents / 25;
    cents %= 25;

    coins += cents /10;
    cents %= 10;

    coins += cents / 5;
    cents %= 5;

    coins += cents;
    return coins;
}