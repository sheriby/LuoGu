#include <cstdio>
const int MAX = 10e4 + 1;

int x[MAX]{0};
int y[MAX]{0};
int lenx[MAX]{0};
int leny[MAX]{0};

int main(int argc, char const *argv[]) {
    int n, x0, y0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x[i], &y[i], &lenx[i], &leny[i]);
    }
    scanf("%d%d", &x0, &y0);

    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
        if (x0 - x[i] <= lenx[i] && x0 >= x[i] && y0 - y[i] <= leny[i] &&
            y0 >= y[i]) {
            printf("%d\n", i + 1);
            flag = true;
            break;
        }
    }

    if (!flag) {
        printf("-1");
    }

    return 0;
}
