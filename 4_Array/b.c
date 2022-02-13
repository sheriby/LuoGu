#include <stdio.h>

int ans[100];

int main(int argc, const char *argv[]) {
    int i;
    for (i = 0; i < 100; i++) {
        scanf("%d", &ans[i]);
        if (ans[i] == 0)
            break;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", ans[j]);
        if (j != 0)
            printf(" ");
    }
    return 0;
}