#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, x, cur = 0, max = 1, start = 1, pre = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (start) {
            cur++;
            pre = x;
            start = 0;
        } else {
            if (x == pre + 1) {
                cur++;
                pre = x;
                if (cur > max)
                    max = cur;
            } else {
                cur = 1;
                pre = x;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}