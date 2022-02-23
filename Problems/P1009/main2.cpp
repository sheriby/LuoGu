#include <cstdio>
#include <cstring>
const int MAX = 1000;

char sum[MAX]{0};
char cur[MAX]{0};

void plus(char *a, int b) {
    int jw = 0, numa, tmp;
    for (int i = 0; i < MAX; i++) {
        numa = a[i] - '0';
        tmp = numa * b + jw;
        jw = tmp / 10;
        a[i] = (tmp % 10) + '0';
    }
}

void add(char *a, char *b) {
    int jw = 0, numa, numb, tmp;
    for (int i = 0; i < MAX; i++) {
        numa = a[i] - '0';
        numb = b[i] - '0';
        tmp = numa + numb + jw;
        jw = tmp / 10;
        a[i] = (tmp % 10) + '0';
    }
}

void print(char *a) {
    bool flag = true;
    for (int i = MAX - 1; i >= 0; i--) {
        if (a[i] == '0' && flag)
            continue;
        else {
            printf("%c", a[i]);
            flag = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    memset(sum, '0', MAX);
    memset(cur, '0', MAX);
    cur[0] = '1';
    for (int i = 1; i <= n; i++) {
        plus(cur, i);
        add(sum, cur);
    }

    print(sum);
    return 0;
}
