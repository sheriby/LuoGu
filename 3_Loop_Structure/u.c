#include <stdio.h>

int main(int argc, const char *argv[]) {
    int cun = 0, cur = 0, x;
    for (int i = 1; i <= 12; i++) {
        cur += 300;
        scanf("%d", &x);
        if (cur < x) {
            printf("-%d\n", i);
            return 0;
        }
        cur -= x;
        if (cur >= 100) {
            cun += cur / 100 * 100;
            cur = cur % 100;
        }
    }
    printf("%d\n", (int)(cun * 1.2) + cur);
    return 0;
}