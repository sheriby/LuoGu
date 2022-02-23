#include <stdio.h>

int res[10000][10];
int tmp[10];
int cnt = 0;
int n;

void run(int ind, int s) {
    if (10 - ind + s > n || 3 * (10 - ind) + s < n)
        return;
    if (ind == 10) {
        if (s == n) {
            for (int i = 0; i < 10; i++) {
                res[cnt][i] = tmp[i];
            }
            cnt++;
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        tmp[ind] = i;
        run(ind + 1, s + i);
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    run(0, 0);
    if (!cnt) {
        printf("0\n");
        return 0;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", res[i][j]);
            if (j != 9)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}