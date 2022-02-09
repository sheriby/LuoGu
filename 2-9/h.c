#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a, b, ind = 0, ans = 8, sum;
    for (int i = 1; i <= 7; i++) {
        scanf("%d%d", &a, &b);
        sum = a + b;
        if (sum > ans) {
            ind = i;
            ans = sum;
        }
    }
    printf("%d\n", ind);
    return 0;
}
