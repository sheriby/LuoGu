#include <stdio.h>
#define MAX 10001

int x[MAX];
int y[MAX];
int lenx[MAX];
int leny[MAX];

// 暴击模拟
int main(int argc, char const *argv[]) {
    int n, x0, y0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x[i], &y[i], &lenx[i], &leny[i]);
    }
    scanf("%d%d", &x0, &y0);

    int flag = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x0 - x[i] <= lenx[i] && x0 >= x[i] && y0 - y[i] <= leny[i] &&
            y0 >= y[i]) {
            printf("%d\n", i + 1);
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("-1");
    }

    return 0;
}
