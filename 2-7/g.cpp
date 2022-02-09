#include <cstdio>

int main(int argc, char const *argv[]) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int h = c - a;
    int m = d - b;
    if (m < 0) {
        m += 60;
        h--;
    }
    printf("%d %d\n", h, m);
    return 0;
}
