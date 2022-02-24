#include <math.h>
#include <stdio.h>

int cnt = 0;
int n;
int tmp[14];

// 没有剪枝，容易TLE
int isvalid(int ind, int pos) {
    for (int i = 1; i < ind; i++) {
        if (tmp[i] == pos)
            return 0;
        if (abs(ind - i) == abs(pos - tmp[i]))
            return 0;
    }
    return 1;
}

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
        if (isvalid(ind, i)) {
            tmp[ind] = i;
            run(ind + 1);
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