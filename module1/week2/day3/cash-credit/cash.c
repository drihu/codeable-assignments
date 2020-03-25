#include <stdio.h>
#include <math.h>
#include <cs50.h>

float getPositive(void);
int drawer(int cents);

int main(void) {
    float change = getPositive();
    int cents = round(change * 100);
    int coins = drawer(cents);
    printf("%i\n", coins);
}

float getPositive(void) {
    float number;
    do {
        number = get_float("Change owed: ");
    } while (number < 0);
    return number;
}

int drawer(cents) {
    int amount = cents;
    int coins = 0;

    coins = coins + floor(amount / 25);
    amount = amount % 25;
    coins = coins + floor(amount / 10);
    amount = amount % 10;
    coins = coins + floor(amount / 5);
    amount = amount % 5;
    coins = coins + amount;

    return coins;
}
