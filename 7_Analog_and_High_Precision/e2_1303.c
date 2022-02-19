#include <stdio.h>
#include <string.h>

int a[4004], b[4004], c[4004];

int main(int argc, const char *argv[]) {
    char stra[2002], strb[2002];
    scanf("%s%s", &stra, &strb);
    int lena = strlen(stra), lenb = strlen(strb);
    for (int i = 0; i < lena; i++) {
        a[i] = stra[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        b[i] = strb[lenb - i - 1] - '0';
    }

    for (int i = 0; i < lena; i++) {
        for (int j = 0; j < lenb; j++) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / 10;
            c[i + j] %= 10;
        }
    }

    int flag = 1;
    for (int i = 4003; i >= 0; i--) {
        if (flag && c[i] == 0)
            continue;
        printf("%d", c[i]);
        flag = 0;
    }
    if (flag) {
        printf("0");
    }

    return 0;
}