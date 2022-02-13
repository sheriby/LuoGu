#include <stdio.h>

int ans[40][40];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int prei = 0, prej = n >> 1;
    ans[prei][prej] = 1;
    for (int i = 2; i <= n * n; i++) {
        if (prei == 0 && prej != n - 1) {
            prei = n - 1;
            prej++;
        } else if (prej == n - 1 && prei != 0) {
            prei--;
            prej = 0;
        } else if (prei == 0 && prej == n - 1) {
            prei++;
        } else {
            if (ans[prei - 1][prej + 1] == 0) {
                prei--;
                prej++;
            } else {
                prei++;
            }
        }
        ans[prei][prej] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", ans[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}