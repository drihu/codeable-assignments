#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

int main(void) {
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int index;

    for (int i = 0; i < length; i++) {
        if (text[i] == ' ') {
            words += 1;
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences += 1;
        } else if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)) {
            letters += 1;
        }
    }
    words += 1;

    index = round(5.88 * ((float) letters / words) - 29.6 * ((float) sentences / words) - 15.8);

    if (index >= 16) {
        printf("Grade 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", index);
    }
}
