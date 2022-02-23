#include <stdio.h>

int num[101];
int res[101];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (num[i] > num[j])
                res[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", res[i]);
        if (i != n - 1)
            printf(" ");
    }
    return 0;
}