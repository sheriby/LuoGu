#include <stdio.h>

char map[101][101];

int main(int argc, const char *argv[]) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", &map[i]);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        int start = -1;
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.' && start == -1) {
                start = j;
            } else if (map[i][j] == '#' && start != -1) {
                if (j - start >= k)
                    s += j - start - k + 1;

                start = -1;
            }
        }
        if (start != -1 && n - start >= k)
            s += m - start - k + 1;
    }
    if (k != 1) {
        for (int i = 0; i < m; i++) {
            int start = -1;
            for (int j = 0; j < n; j++) {
                if (map[j][i] == '.' && start == -1) {
                    start = j;
                } else if (map[j][i] == '#' && start != -1) {
                    if (j - start >= k)
                        s += j - start - k + 1;
                    start = -1;
                }
            }
            if (start != -1 && m - start >= k)
                s += n - start - k + 1;
        }
    }

    printf("%d\n", s);
    return 0;
}