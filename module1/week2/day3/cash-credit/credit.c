#include <stdio.h>
#include <math.h>
#include <cs50.h>

string verify(long number);
int length(long number);
int firstDigit(long number);
int firstTwoDigits(long number);
int sumOfDigits(int number);

int main(void) {
    long number = get_long("Number: ");
    string message = verify(number);
    printf("%s\n", message);
}

string verify(long number) {
    int checksum = 0;
    int times = round(length(number) / 2.0);
    int digit;
    long amount = number;
    for (int i = 0; i < times; i++) {
        digit = floor((amount % 100) / 10.0);
        checksum += sumOfDigits(digit * 2);
        amount = floor(amount / 100);
    }
    amount = number;
    for (int j = 0; j < times; j++) {
        digit = amount % 10;
        checksum += digit;
        amount = floor(amount / 100);
    }
    if (checksum % 10 == 0) {
        if (firstDigit(number) == 4) {
            return "VISA";
        } else if (firstTwoDigits(number) == 34 || firstTwoDigits(number) == 37) {
            return "AMEX";
        } else if (firstTwoDigits(number) > 50 && firstTwoDigits(number) < 56) {
            return "MASTERCARD";
        }
    }
    return "INVALID";
}

int length(long number) {
    long amount = number;
    int len = 0;
    while (amount >= 1) {
        amount /= 10;
        len += 1;
    }
    return len;
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

int firstDigit(long number) {
    int num = floor(number / pow(10, length(number) - 1));
    return num;
}

int firstTwoDigits(long number) {
    int num = floor(number / pow(10, length(number) - 2));
    return num;
}
