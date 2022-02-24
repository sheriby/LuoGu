#include <stdio.h>

int cnt = 0;
int n;
int tmp[14];
int check[3][28];

void run(int ind) {
    if (ind == n + 1) {
        if (cnt++ < 3) {
            for (int i = 1; i <= n; i++) {
                printf("%d", tmp[i]);
                if (i != n)
                    printf(" ");
            }
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        // 所在列，主对角线，副对角线没有被占领
        if (!check[0][i] && !check[1][i + ind] && !check[2][i - ind + n]) {
            tmp[ind] = i;
            // 标记和取消标记
            check[0][i] = 1, check[1][i + ind] = 1, check[2][i - ind + n] = 1;
            run(ind + 1);
            check[0][i] = 0, check[1][i + ind] = 0, check[2][i - ind + n] = 0;
        }
    }
}

// 递归与回溯
int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    run(1);
    printf("%d\n", cnt);
    return 0;
}