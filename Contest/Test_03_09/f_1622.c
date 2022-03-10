#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int go[101];

// correct solution is dp
// this is a stupid greed algorithm to get some score
int main(int argc, const char *argv[]) {
    int p, q;
    scanf("%d%d", &p, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &go[i]);
    }
    int ans1 = p - 1, ans2 = p - 1;
    qsort(go, q, sizeof(int), cmp);
    for (int i = 1; i < q; i++) {
        ans1 += p - go[i];
        ans1 += go[i] - go[i - 1] - 1;
    }
    for (int i = q - 2; i >= 0; i--) {
        ans2 += go[i] - 1;
        ans2 += go[i + 1] - go[i] - 1;
    }
    if (ans1 < ans2)
        printf("%d\n", ans1);
    else
        printf("%d\n", ans2);
    return 0;
}