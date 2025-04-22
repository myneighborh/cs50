# CS50 Pset1 Solutions

This repository contains solutions for Problem Set 1 (pset1) from Harvard's CS50 course.

## Files

### `hello.c`
- Prints "Hello, world!" to the screen.

### `mario.c`
- Prints a pyramid of hashes (`#`) for visual patterning.

### `cash.c`
- Calculates the minimum number of coins needed to give change.
- **Uses a Greedy Algorithm**: Always uses the largest possible coin value first (quarters → dimes → nickels → pennies).
- Ensures accuracy by converting dollars to cents and using integer arithmetic.

### `credit.c`
- Validates credit card numbers using Luhn’s Algorithm.
- Determines card type (AMEX, MASTERCARD, VISA) based on number pattern.
