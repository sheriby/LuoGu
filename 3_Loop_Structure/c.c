#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int k = 0;
    while (n) {
        n >>= 1;
        k++;
    }
    printf("%d\n", k);
    return 0;
}