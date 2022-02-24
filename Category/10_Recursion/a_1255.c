#include <stdio.h>
#include <string.h>

int a[5005];
int b[5005];
int tmp[5005];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    a[0] = 1;
    b[0] = 1;
    // 记录长度，优化高精度加法
    int len = 1;
    for (int i = 2; i <= n; i++) {
        memcpy(tmp, a, sizeof(a));
        int jw = 0;
        for (int i = 0; i < len; i++) {
            a[i] = a[i] + b[i] + jw;
            jw = a[i] / 10;
            a[i] = a[i] % 10;
        }
        while (jw) {
            a[len++] = jw % 10;
            jw /= 10;
        }
        memcpy(b, tmp, sizeof(tmp));
    }
    int flag = 1;
    for (int i = 5004; i >= 0; i--) {
        if (flag && a[i] == 0)
            continue;
        printf("%d", a[i]);
        flag = 0;
    }
    return 0;
}