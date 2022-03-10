#include <stdio.h>

int main(int argc, const char *argv[]) {
    int a, b, c, d, x, y;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    x = c - a, y = d - b;
    if (y < 0)
        y += 60, x--;
    printf("%d %d\n", x, y);
    return 0;
}