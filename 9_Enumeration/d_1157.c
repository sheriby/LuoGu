#include <stdio.h>

int n, r;
int tmp[21];
int cur = 1;

void run(int ind) {
    if (ind == r) {
        for (int i = 0; i < r; i++) {
            printf("%3d", tmp[i]);
        }
        printf("\n");
        return;
    }
    for (int i = cur; i <= n; i++) {
        tmp[ind] = i;
        cur = i + 1;
        run(ind + 1);
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &r);
    run(0);
    return 0;
}