#include <math.h>
#include <stdio.h>
#include <string.h>

int f[1001], res[1001], sav[1001];

void pow1() {
    memset(sav, 0, sizeof(sav));
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            sav[i + j] += res[i] * f[j];
        }
    }
    for (int i = 0; i < 500; i++) {
        sav[i + 1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(res, sav, sizeof(sav));
}

void pow2() {
    memset(sav, 0, sizeof(sav));
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            sav[i + j] += f[i] * f[j];
        }
    }
    for (int i = 0; i < 500; i++) {
        sav[i + 1] += sav[i] / 10;
        sav[i] %= 10;
    }
    memcpy(f, sav, sizeof(sav));
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    printf("%d\n", (int)(log10(2) * n + 1));
    res[0] = 1;
    f[0] = 2;
    while (n) {
        if (n & 1)
            pow1();
        pow2();
        n >>= 1;
    }
    res[0]--;
    for (int i = 499; i >= 0; i--) {
        printf("%d", res[i]);
        if (i % 50 == 0)
            printf("\n");
    }

    return 0;
}