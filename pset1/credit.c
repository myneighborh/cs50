#include <cs50.h>
#include <stdio.h>

bool check_luhn(long number);
string get_card_type(long number);
int get_length(long number);
int get_start_digits(long number, int digits);

int main(void)
{
    // Prompt the user for card number
    long number = get_long("Number: ");

    // Check VALID or INVALID
    if (check_luhn(number))
    {
        printf("%s\n", get_card_type(number));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_luhn(long number)
{
    int sum = 0;
    int count = 0;

    while (number > 0)
    {
        // Get the last digit by taking modulo 10
        int digit = number % 10;

        // Odd-positioned digit(from the right)
        if (count % 2 == 0)
        {
            sum += digit;
        }

        // Even-positioned digit(from the right)
        else
        {
            // Handles the case where doubling results in a two-digit number
            int doubled = digit * 2;
            sum += (doubled / 10) + (doubled % 10);
        }

        // Remove the last digit
        number /= 10;
        count++;
    }

    return sum % 10 == 0;
}

string get_card_type(long number)
{
    int length = get_length(number);
    int first_two = get_start_digits(number, 2);
    int first_one = get_start_digits(number, 1);

    if ((first_two == 34 || first_two == 37) && length == 15)
    {
        return "AMEX";
    }
    else if (first_two >= 51 && first_two <= 55 && length == 16)
    {
        return "MASTERCARD";
    }
    else if (first_one == 4 && (length == 13 || length == 16))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

int get_length(long number)
{
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

int get_start_digits(long number, int digits)
{
    if (digits == 2)
    {
        while (number >= 100)
        {
            number /= 10;
        }
    }
    else if (digits == 1)
    {
        while (number >= 10)
        {
            number /= 10;
        }
    }
    return number;
}
