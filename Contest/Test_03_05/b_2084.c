#include <stdio.h>
#include <string.h>

char num[1001];

int main(int argc, const char *argv[]) {
    int m;
    scanf("%d%s", &m, &num);
    int p = strlen(num) - 1;
    int start = 1;
    for (int i = 0; i <= p; i++) {
        if (num[i] != '0') {
            if (!start)
                printf("+");
            printf("%c*%d^%d", num[i], m, p - i);
            start = 0;
        }
    }
    return 0;
}