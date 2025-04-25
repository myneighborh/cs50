#include <cs50.h>
#include <math.h>
#include <stdio.h>

int calculate_coins(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Changed owed: ");
    }
    while (cents < 0);

    int coins = calculate_coins(cents);
    printf("%i\n", coins);
}

int calculate_coins(int cents)
{
    // Calculate how many coins you should give customer
    int coins = 0;
    coins += cents / 25;
    cents %= 25;

    coins += cents / 10;
    cents %= 10;

    coins += cents / 5;
    cents %= 5;

    coins += cents;
    return coins;
}
