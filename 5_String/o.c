#include <stdio.h>
#include <string.h>

int map[26];
char str[101];
int main(int argc, const char *argv[]) {
    char ch;
    for (int i = 0; i < 4; i++) {
        gets(str);
        for (int j = 0; j < strlen(str); j++) {
            if (str[j] >= 'A' && str[j] <= 'Z')
                map[str[j] - 'A']++;
        }
    }
    int max = 0;
    for (int i = 0; i < 26; i++) {
        if (map[i] > max)
            max = map[i];
    }

    for (int i = max; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            if (map[j] >= i)
                printf("*");
            else
                printf(" ");
            if (j != 25)
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++) {
        printf("%c", 'A' + i);
        if (i != 25)
            printf(" ");
    }
    return 0;
}