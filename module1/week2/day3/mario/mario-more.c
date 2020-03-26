#include <stdio.h>
#include <cs50.h>

int getPositive(string question);
void printPyramid(int height);
void printChar(char c, int n);

int main(void) {
    int height = getPositive("Height: ");
    printPyramid(height);
}

int getPositive(string question) {
    int h;
    do {
        h = get_int("%s", question);
    } while (h < 1 || h > 8);
    return h;
}

void printPyramid(int height) {
    for (int i = 1; i <= height; i++) {
        printChar(' ', height - i);
        printChar('#', i);
        printf("  ");
        printChar('#', i);
        printf("\n");
    }
}

void printChar(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
}
