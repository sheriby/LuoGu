#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int min = 1000, x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 0) {
            printf("0\n");
            return 0;
        }
        if (x < min)
            min = x;
    }
    printf("%d\n", min);
    return 0;
}