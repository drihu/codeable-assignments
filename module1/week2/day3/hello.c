#include <stdio.h>
#include <cs50.h>

/**
 * Say hello to the user
 */
int main(void)
{
    string name = get_string("What's your name?\n");
    printf("Hello, %s\n", name);
}
