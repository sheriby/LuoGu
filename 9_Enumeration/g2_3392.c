#include <stdio.h>

char line[51];
int w[51], b[51], r[51];
int minv = 0x7fffffff;

// 枚举
int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &line);
        for (int j = 0; j < m; j++) {
            if (line[j] != 'W')
                w[i]++;
            if (line[j] != 'B')
                b[i]++;
            if (line[j] != 'R')
                r[i]++;
        }
        w[i] += w[i - 1];
        b[i] += b[i - 1];
        r[i] += r[i - 1];
    }
    int val = 0;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            int val = w[i] + b[j] - b[i] + r[n] - r[j];
            if (val < minv)
                minv = val;
        }
    }
    printf("%d\n", minv);
    return 0;
}