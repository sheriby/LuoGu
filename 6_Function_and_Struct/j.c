#include <stdio.h>
#define MAX 10001

int prime[MAX];
int visit[MAX];
int cnt = 0;

void init() {
    visit[0] = 1;
    visit[1] = 1;

    for (int i = 2; i < MAX; i++) {
        if (!visit[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < MAX; j++) {
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    init();
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; j < cnt && prime[j] < i; j++) {
            if (!visit[i - prime[j]]) {
                printf("%d=%d+%d\n", i, prime[j], i - prime[j]);
                break;
            }
        }
    }
    return 0;
}