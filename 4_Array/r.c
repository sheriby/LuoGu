#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int sum = 0, x, state = 0;
    while (sum < n * n) {
        scanf("%d", &x);
        for (int i = 0; i < x; i++) {
            printf("%d", state);
            sum++;
            if (sum % n == 0)
                printf("\n");
        }
        state = !state;
    }
    return 0;
}