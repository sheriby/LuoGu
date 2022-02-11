#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%02d", k++);
        }
        printf("\n");
    }
    printf("\n");
    k = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (j >= i)
                printf("%02d", k++);
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}