#include <cstdio>

int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d", &n);
    for (int i = n; i >= 0; i--) {
        scanf("%d", &x);
        if (x == 0)
            continue;
        if (x > 0 && i != n)
            printf("+");
        if (x == -1)
            printf("-");
        else if (x != 1)
            printf("%d", x);
        if (i == 1)
            printf("x");
        else if (i != 0)
            printf("x^%d", i);
        else if (x == 1 || x == -1)
            printf("1");
    }
    return 0;
}