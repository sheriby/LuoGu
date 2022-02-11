#include <stdio.h>

#define MAXN 10000005

int prime[MAXN];
int pp[MAXN];
int vis[MAXN];
int is_huiwen(int x) {

    int y = x, num = 0;
    while (y != 0) {
        num = num * 10 + y % 10;
        y /= 10;
    }
    if (num == x)
        return 1;
    else
        return 0;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = 0;
    if (b > 10000000)
        b = 10000000;
    for (int i = 3; i <= b; i += 2) {
        if (!vis[i])
            prime[cnt++] = i, pp[i] = 1;
        for (int j = 0; j < cnt && i * prime[j] <= b; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = a; i <= b; i++) {
        if (pp[i] && is_huiwen(i))
            printf("%d\n", i);
    }
}