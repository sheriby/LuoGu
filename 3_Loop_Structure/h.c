#include <stdio.h>

int main(int argc, const char *argv[]) {
    int k;
    scanf("%d", &k);
    int i;
    for (i = 0; i * (i + 1) <= 2 * k; i++)
        ;
    int ans = (i - 1) * i * (2 * i - 1) / 6 + i * (k - i * (i - 1) / 2);
    printf("%d", ans);
    return 0;
}