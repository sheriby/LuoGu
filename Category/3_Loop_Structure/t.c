#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d", &n);
    for (int i = 1092;; i += 1092) {
        if ((n - i) % 364 == 0) {
            int x = (n - i) / 364;
            if (x > 100)
                continue;
            printf("%d\n%d\n", x, i / 1092);
            break;
        }
    }
    return 0;
}