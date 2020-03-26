#include <stdio.h>
#include <math.h>
#include <cs50.h>

string verify(long number);
int sumOfDigits(int number);

int main(void) {
    long number = get_long("Number: ");
    string message = verify(number);
    printf("%s\n", message);
}

string verify(long number) {
    long amount = number;
    int checksum1 = 0;
    int checksum2 = 0;
    int checksum;
    int secondDigit;
    int digit = 0;
    int i = 1;

    while (amount > 0) {
        secondDigit = digit;
        digit = amount % 10;
        if (i % 2 == 0) checksum1 += sumOfDigits(digit * 2);
        else checksum2 += digit;
        i += 1;
        amount = floor(amount / 10);
    }

    checksum = checksum1 + checksum2;

    if (checksum % 10 == 0) {
        if (digit == 4) {
            return "VISA";
        } else if ((digit * 10 + secondDigit) == 34 || (digit * 10 + secondDigit) == 37) {
            return "AMEX";
        } else if ((digit * 10 + secondDigit) > 50 && (digit * 10 + secondDigit) < 56) {
            return "MASTERCARD";
        }
    }
    return "INVALID";
}

int sumOfDigits(int number) {
    int amount = number;
    int sum = 0;
    while (amount > 0) {
        sum += amount % 10;
        amount /= 10;
    }
    return sum;
}
