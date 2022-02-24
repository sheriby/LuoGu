#include <stdio.h>
#include <string.h>

int a[1000];
int b[1000];
int tmp[1000];

int main(int argc, const char *argv[]) {
    int m, n;
    scanf("%d%d", &m, &n);
    a[0] = 1;
    b[0] = 1;
    int len = 1;
    for (int i = m + 2; i <= n; i++) {
        // a => tmp ; a + b => a ; tmp => b
        memcpy(tmp, a, sizeof(tmp));
        int jw = 0;
        for (int i = 0; i < len; i++) {
            a[i] = a[i] + b[i] + jw;
            jw = a[i] / 10;
            a[i] %= 10;
        }
        while (jw) {
            a[len++] = jw % 10;
            jw /= 10;
        }
        memcpy(b, tmp, sizeof(tmp));
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
    return 0;
}