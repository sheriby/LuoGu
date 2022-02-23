#include <stdio.h>
int n;
int map[10];
int tmp[10];
int cnt = 0;

void run(int ind) {
    if (ind == n) {
        for (int i = 0; i < n; i++) {
            printf("%5d", map[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (tmp[i])
            continue;
        map[ind] = i;
        tmp[i] = 1;
        run(ind + 1);
        tmp[i] = 0;
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    run(0);
    return 0;
}