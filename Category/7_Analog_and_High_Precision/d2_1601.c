#include <stdio.h>
#include <string.h>

int a[502], b[502], c[503];

int main(int argc, const char *argv[]) {
    char stra[502], strb[502];
    scanf("%s%s", &stra, &strb);
    int lena = strlen(stra), lenb = strlen(strb), max_len;
    for (int i = 0; i < lena; i++) {
        a[i] = stra[lena - i - 1] - '0';
    }
    for (int i = 0; i < lenb; i++) {
        b[i] = strb[lenb - i - 1] - '0';
    }

    if (lena > lenb)
        max_len = lena;
    else
        max_len = lenb;

    int jw = 0;
    for (int i = 0; i < max_len + 1; i++) {
        c[i] = a[i] + b[i] + jw;
        jw = c[i] / 10;
        c[i] %= 10;
    }

    int flag = 1;
    for (int i = 502; i >= 0; i--) {
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