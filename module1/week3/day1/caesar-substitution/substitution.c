#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

bool isValidKey(string text);

int main(int argc, string argv[]) {
    if (argc == 1 || argc > 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    } else if (strlen(argv[1]) != 26 || !isValidKey(argv[1])) {
        printf("Key must contain 26 alphabetic characters and each letter exactly once.\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = argv[1];

    printf("ciphertext: ");
    for (int i = 0, len = strlen(text); i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                if (text[i] == base[j]) {
                    printf("%c", toupper(key[j]));
                    break;
                }
            } else if (text[i] >= 'a' && text[i] <= 'z') {
                if (text[i] == tolower(base[j])) {
                    printf("%c", tolower(key[j]));
                    break;
                }
            } else {
                printf("%c", text[i]);
                break;
            }
        }
    }
    printf("\n");
}

bool isValidKey(string text) {
    for (int i = 0, len = strlen(text); i < len; i++) {
        if (!isalpha(text[i])) return false;

        for (int j = 0; j < len - 1 - i; j++) {
            if (toupper(text[i]) == toupper(text[i + j + 1])) return false;
        }
    }
    return true;
}
