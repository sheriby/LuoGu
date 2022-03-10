#include <stdio.h>

int n;
int res[10];
int vis[10];

void run(int ind) {
    if (ind == n) {
        for (int i = 0; i < n; i++) {
            printf("%5d", res[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        res[ind] = i;
        vis[i] = 1;
        run(ind + 1);
        vis[i] = 0;
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    run(0);
    return 0;
}