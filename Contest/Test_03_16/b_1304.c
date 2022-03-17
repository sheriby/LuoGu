#include <stdio.h>

int arr[10001];
int prime[10001];
int cnt = 0;
int n;

void init() {
    for (int i = 2; i <= n; i++) {
        if (!arr[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i <= n; j++) {
            arr[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    init();
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; j < cnt; j++) {
            if (!arr[prime[j]] && !arr[i - prime[j]]) {
                printf("%d=%d+%d\n", i, prime[j], i - prime[j]);
                break;
            }
        }
    }
    return 0;
}