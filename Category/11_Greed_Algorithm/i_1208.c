#include <stdio.h>
#include <stdlib.h>

struct Milk {
    int price;
    int amount;
} milks[5001];

int cmp(const void *a, const void *b) {
    return ((struct Milk *)a)->price - ((struct Milk *)b)->price;
}

int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &milks[i].price, &milks[i].amount);
    }
    qsort(milks, m, sizeof(struct Milk), cmp);
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (n > milks[i].amount) {
            ans += milks[i].amount * milks[i].price;
            n -= milks[i].amount;
        } else {
            ans += n * milks[i].price;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}