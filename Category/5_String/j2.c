#include <stdio.h>
#include <string.h>

char str[256];
int main(int argc, const char *argv[]) {
    scanf("%s", &str);
    int b = 0, g = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'b' || str[i + 1] == 'o' || str[i + 2] == 'y') {
            b++;
        }
        if (str[i] == 'g' || str[i + 1] == 'i' || str[i + 2] == 'r' ||
            str[i + 3] == 'l') {
            g++;
        }
    }
    printf("%d\n%d\n", b, g);
    return 0;
}