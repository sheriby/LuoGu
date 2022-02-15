#include <stdio.h>
#include <string.h>

char str[256];

int main(int argc, const char *argv[]) {
    scanf("%s", &str);
    char ch;
    int b = 0, g = 0;
    for (int i = 0; i < strlen(str); i++) {
        ch = str[i];
        switch (ch) {
        case '.':
            break;
        case 'b':
            if (str[i + 1] != 'o') {
                b++;
                break;
            } else
                i++;
        case 'o':
            if (str[i + 1] != 'y') {
                b++;
                break;
            } else
                i++;
        case 'y':
            b++;
            break;
        case 'g':
            if (str[i + 1] != 'i') {
                g++;
                break;
            } else
                i++;
        case 'i':
            if (str[i + 1] != 'r') {
                g++;
                break;
            } else
                i++;
        case 'r':
            if (str[i + 1] != 'l') {
                g++;
                break;
            } else
                i++;
        case 'l':
            g++;
            break;
        }
    }
    printf("%d\n%d\n", b, g);
    return 0;
}