#include <stdio.h>
#include <string.h>

char a[4004];
char b[4004];
char tmp[4004];
char res[4004];

void reverse(char a[], int len) {
    int l = 0, r = len - 1;
    char ch;
    while (l < r) {
        ch = a[l];
        a[l] = a[r];
        a[r] = ch;
        l++;
        r--;
    }
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int c2int(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return 0;
}

char int2c(int i) { return i + '0'; }

void plus(char x[], int b, int len) {
    int jw = 0, t;
    for (int i = 0; i < len; i++) {
        t = c2int(x[i]) * b + jw;
        tmp[i] = int2c(t % 10);
        jw = t / 10;
    }
    if (jw) {
        tmp[len] = int2c(jw);
        tmp[len + 1] = 0;
    } else
        tmp[len] = 0;
}

void add(char x[], char y[], int len) {
    int jw = 0, t;
    for (int i = 0; i < len; i++) {
        t = c2int(x[i]) + c2int(y[i]) + jw;
        x[i] = int2c(t % 10);
        jw = t / 10;
    }
    if (jw) {
        x[len] = int2c(jw);
        x[len + 1] = 0;
    } else
        x[len] = 0;
}

int is_zero(char x[]) {
    char *p = x;
    while (*p) {
        if (*p++ != '0')
            return 0;
    }
    return 1;
}

void shift(char x[], int len, int s) {
    if (is_zero(x))
        return;
    if (s == 0)
        return;
    for (int i = len - 1; i >= 0; i--) {
        x[i + s] = x[i];
    }
    for (int i = 0; i < s; i++) {
        x[i] = '0';
    }
    x[len + s] = 0;
}

int main(int argc, const char *argv[]) {
    scanf("%s%s", &a, &b);
    if (is_zero(a) || is_zero(b)) {
        printf("0\n");
        return 0;
    }
    int lena = strlen(a), lenb = strlen(b), maxlen;
    reverse(a, lena);
    reverse(b, lenb);
    res[0] = '0';

    for (int i = 0; i < lenb; i++) {
        if (b[i] == '0')
            continue;
        plus(a, c2int(b[i]), strlen(a));
        shift(tmp, strlen(tmp), i);
        // printf("tmp: %s\n", tmp);
        add(res, tmp, max(strlen(res), strlen(tmp)));
        // printf("res: %s\n", res);
    }

    reverse(res, strlen(res));
    printf("%s\n", res);

    return 0;
}