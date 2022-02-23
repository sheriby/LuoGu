#include <stdio.h>
#include <string.h>

char buf[1024];
char str[128];

int to_int(char *a) {
    int res = 0;
    while (*a) {
        res = res * 10 + *a - '0';
        a++;
    }
    return res;
}

int main(int argc, const char *argv[]) {
    int n, a, b, mode;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &str);
        if (str[0] >= 'a') {
            mode = str[0] - 'a';
            scanf("%d%d", &a, &b);
        } else {
            a = to_int(str);
            scanf("%d", &b);
        }

        switch (mode) {
        case 0:
            sprintf(buf, "%d+%d=%d", a, b, a + b);
            break;
        case 1:
            sprintf(buf, "%d-%d=%d", a, b, a - b);
            break;
        case 2:
            sprintf(buf, "%d*%d=%d", a, b, a * b);
            break;
        }
        printf("%s\n%d\n", buf, strlen(buf));
    }

    return 0;
}