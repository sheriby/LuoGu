#include <stdio.h>

int arr[501][501];
int tmp[501][501];

void reverse(int x, int y, int r, int z) {
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            tmp[i][j] = arr[i][j];
        }
    }
    for (int i = x - r; i <= x + r; i++) {
        for (int j = y - r; j <= y + r; j++) {
            if (z)
                arr[i][j] = tmp[j - y + x][x + y - i];
            else
                arr[i][j] = tmp[x + y - j][i - x + y];
        }
    }
}

int main(int argc, const char *argv[]) {
    int n, m;
    int x, y, r, z;
    int k = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = k++;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &x, &y, &r, &z);
        reverse(x, y, r, z);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", arr[i][j]);
            if (j != n)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}