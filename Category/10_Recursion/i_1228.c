#include <stdio.h>

#define run1 run(x, y, len / 2, x + len / 2 - 1, y + len / 2 - 1);
#define run2 run(x, y + len / 2, len / 2, x + len / 2 - 1, y + len / 2);
#define run3 run(x + len / 2, y, len / 2, x + len / 2, y + len / 2 - 1);
#define run4 run(x + len / 2, y + len / 2, len / 2, x + len / 2, y + len / 2);

void run(int x, int y, int len, int p, int q) {
    if (len == 1)
        return;
    if (p - x < len / 2 && q - y < len / 2) {
        run(x, y, len / 2, p, q); // 左上
        printf("%d %d 1\n", x + len / 2, y + len / 2);
        run2 run3 run4
    } else if (p - x < len / 2 && q - y >= len / 2) {
        run(x, y + len / 2, len / 2, p, q); // 右上
        printf("%d %d 2\n", x + len / 2, y + len / 2 - 1);
        run1 run3 run4
    } else if (p - x >= len / 2 && q - y < len / 2) {
        run(x + len / 2, y, len / 2, p, q); // 左下
        printf("%d %d 3\n", x + len / 2 - 1, y + len / 2);
        run1 run2 run4
    } else if (p - x >= len / 2 && q - y >= len / 2) {
        run(x + len / 2, y + len / 2, len / 2, p, q); // 右下
        printf("%d %d 4\n", x + len / 2 - 1, y + len / 2 - 1);
        run1 run2 run3
    }
}

int main(int argc, const char *argv[]) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    run(1, 1, 1 << n, x, y);
    return 0;
}