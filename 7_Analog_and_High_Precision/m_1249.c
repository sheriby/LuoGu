#include <math.h>
#include <stdio.h>
#include <string.h>

int res[30000];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    res[0] = 1;
    int len = 1;
    int k = (int)((-1 + sqrt(1 + 8 * (n + 1))) / 2);
    int y = n - (2 + k) * (k - 1) / 2;
    int flag = 1, p, val = -1, start = 1;
    for (int i = 2; i <= k; i++) {
        int jw = 0;
        p = i;
        if (flag && i + y > k) {
            p = i + y;
            val = p;
            flag = 0;
        } else {
            if (!start)
                printf(" ");
            printf("%d", i);
            start = 0;
        }
        for (int j = 0; j < len; j++) {
            res[j] = res[j] * p + jw;
            jw = res[j] / 10;
            res[j] %= 10;
        }
        while (jw) {
            res[len++] = jw % 10;
            jw /= 10;
        }
    }
    if (val != -1) {
        if (!start)
            printf(" ");
        printf("%d", val);
    }
    printf("\n");

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    return 0;
}