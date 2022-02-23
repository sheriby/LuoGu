#include <math.h>
#include <stdio.h>

int ans[100][100];

int main(int argc, const char *argv[]) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int count = 0, x, y;
    for (int i = 0; i < m + k; i++) {
        scanf("%d%d", &x, &y);
        for (int xi = x - 2; xi <= x + 2; xi++) {
            if (xi < 1 || xi > n)
                continue;
            for (int yi = y - 2; yi <= y + 2; yi++) {
                if (yi < 1 || yi > n)
                    continue;
                if (!ans[xi][yi] &&
                    (i >= m || abs(xi - x) + abs(yi - y) <= 2)) {
                    ans[xi][yi] = 1;
                    count++;
                }
            }
        }
    }
    printf("%d\n", n * n - count);
    return 0;
}