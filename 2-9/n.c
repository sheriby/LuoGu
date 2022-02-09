#include <stdio.h>

int ans[10];

int main(int argc, char const *argv[]) {
    int n, count = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &ans[i]);
    }
    scanf("%d", &n);
    n += 30;
    for (int i = 0; i < 10; i++) {
        if (ans[i] <= n)
            count++;
    }
    printf("%d\n", count);
    return 0;
}
