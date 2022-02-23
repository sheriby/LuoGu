#include <stdio.h>
#include <string.h>

int res[3000];

int factorial(int a) {
    memset(res, 0, sizeof(res));
    res[0] = 1;
    int len = 1;
    for (int i = 2; i <= a; i++) {
        int jw = 0;
        for (int j = 0; j < len; j++) {
            res[j] = res[j] * i + jw;
            jw = res[j] / 10;
            res[j] %= 10;
        }
        while (jw) {
            res[len++] = jw % 10;
            jw /= 10;
        }
    }
    return len;
}

int count(int a, int len) {
    int c = 0;
    for (int i = 0; i < len; i++) {
        if (res[i] == a)
            c++;
    }
    return c;
}

int main(int argc, const char *argv[]) {
    int t;
    scanf("%d", &t);
    int n, a;
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &n, &a);
        int len = factorial(n);
        printf("%d\n", count(a, len));
    }
    return 0;
}