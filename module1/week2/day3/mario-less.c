#include <stdio.h>
#include <cs50.h>

int getPositive(void);
void printPyramid(int height);
void printSpace(int n);
void printHash(int n);

int main(void) {
    int height = getPositive();
    printPyramid(height);
}

int getPositive(void) {
    int h;
    do {
        h = get_int("Height: ");
    } while (h < 1 || h > 8);
    return h;
}

void printPyramid(int height) {
    for (int i = 1; i <= height; i++) {
        printSpace(height - i);
        printHash(i);
        printf("\n");
    }
}

void printSpace(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printHash(int n) {
    for (int i = 0; i < n; i++) {
        printf("#");
    }
}
