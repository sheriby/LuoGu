#include <stdio.h>

int map[1001][1001];
int row[1001];
int col[1001];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                row[i] += map[i][j];
                col[j] += map[i][j];
            }
        }
    }
    int max = 0, tmp, flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!map[i][j]) {
                flag = 0;
                tmp = row[i] + col[j];
                if (tmp > max)
                    max = tmp;
            }
        }
    }
    if (flag)
        printf("Bad Game!\n");
    else
        printf("%d\n", max);
    return 0;
}