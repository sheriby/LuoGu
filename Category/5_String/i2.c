#include <stdio.h>

char str[101];

int main(int argc, const char *argv[]) {
    int n, times;
    scanf("%d%s", &n, &str);
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == 'V' && str[i + 1] == 'K') {
            times++;
            str[i] = 'X';
            str[i + 1] = 'Y';
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            times++;
            break;
        }
    }
    printf("%d\n", times);
    return 0;
}