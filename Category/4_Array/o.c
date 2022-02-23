#include <stdio.h>

int nums[10][10];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int i = 0, j = -1, state = 0;
    int newi = 0, newj = 0, cur = 1;
    while (cur <= n * n) {
        newi = i + dx[state];
        newj = j + dy[state];
        if (nums[newi][newj] != 0 || newi < 0 || newi >= n || newj < 0 ||
            newj >= n) {
            state = (state + 1) % 4;
        } else {
            i = newi;
            j = newj;
            nums[i][j] = cur;
            cur++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}