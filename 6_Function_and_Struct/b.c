#include <stdio.h>
#define MAX 100001

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
    int n, x;
    scanf("%d", &n);

    init();

    int start = 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (!visit[x]) {
            if (!start)
                printf(" ");
            printf("%d", x);
            start = 0;
        }
    }
    return 0;
}