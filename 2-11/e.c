#include <stdio.h>
#define MAX 1000

int sum[MAX];
int cur[MAX];

void plus(int *a, int b) {
    int jw = 0, tmp;
    for (int i = 0; i < MAX; i++) {
        tmp = a[i] * b + jw;
        jw = tmp / 10;
        a[i] = tmp % 10;
    }
}

void add(int *a, int *b) {
    int jw = 0, tmp;
    for (int i = 0; i < MAX; i++) {
        tmp = a[i] + b[i] + jw;
        jw = tmp / 10;
        a[i] = tmp % 10;
    }
}

void print(int *a) {
    int flag = 1;
    for (int i = MAX - 1; i >= 0; i--) {
        if (a[i] == 0 && flag)
            continue;
        else {
            printf("%d", a[i]);
            flag = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    cur[0] = 1;
    for (int i = 1; i <= n; i++) {
        plus(cur, i);
        add(sum, cur);
    }

    print(sum);
    return 0;
}
