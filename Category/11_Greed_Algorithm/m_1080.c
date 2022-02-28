#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    int left;
    int right;
} persons[1001];

int cmp(const void *a, const void *b) {
    return ((struct Person *)a)->left * ((struct Person *)a)->right -
           ((struct Person *)b)->left * ((struct Person *)b)->right;
}

int ans[10000];
int lena = 1;
int maxn[10000];
int lenm = 0;
int tmp[10000];
int lent;

// 高精度加法
void _mul(int x) {
    int jw = 0;
    for (int i = 0; i < lena; i++) {
        ans[i] = ans[i] * x + jw;
        jw = ans[i] / 10;
        ans[i] %= 10;
    }
    while (jw) {
        ans[lena++] = jw % 10;
        jw /= 10;
    }
}

// 高精度除法，向下取整
void _div(int x) {
    memset(tmp, 0, sizeof(tmp));
    int t = 0;
    for (int i = lena - 1; i >= 0; i--) {
        t = t * 10 + ans[i];
        tmp[i] = t / x;
        t %= x;
    }
    int k = lena - 1;
    while (tmp[k] == 0)
        k--;
    lent = k + 1;
}

void _max() {
    if (lenm < lent) {
        memcpy(maxn, tmp, sizeof(tmp));
        lenm = lent;
        return;
    }
    if (lenm == lent) {
        for (int i = lenm - 1; i >= 0; i--) {
            if (tmp[i] > maxn[i]) {
                memcpy(maxn, tmp, sizeof(tmp));
                lenm = lent;
                return;
            } else if (tmp[i] < maxn[i]) {
                return;
            }
        }
    }
}

int main(int argc, const char *argv[]) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &persons[i].left, &persons[i].right);
    }
    qsort(persons, n, sizeof(struct Person), cmp);
    ans[0] = 1;
    _mul(x);
    for (int i = 0; i < n; i++) {
        if (i > 0)
            _mul(persons[i - 1].left);
        _div(persons[i].right);
        _max();
    }
    for (int i = lenm - 1; i >= 0; i--) {
        printf("%d", maxn[i]);
    }
    return 0;
}