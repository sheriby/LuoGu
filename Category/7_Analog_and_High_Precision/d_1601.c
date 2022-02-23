#include <stdio.h>
#include <string.h>

char a[502];
char b[502];

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

int main(int argc, const char *argv[]) {
    scanf("%s%s", &a, &b);
    int lena = strlen(a), lenb = strlen(b), maxlen;
    reverse(a, lena);
    reverse(b, lenb);
    if (lena > lenb)
        maxlen = lena;
    else
        maxlen = lenb;

    int jw = 0, numa, numb, tmp;
    for (int i = 0; i < maxlen; i++) {
        if (a[i] >= '0' && a[i] <= '9')
            numa = a[i] - '0';
        else
            numa = 0;
        if (b[i] >= '0' && b[i] <= '9')
            numb = b[i] - '0';
        else
            numb = 0;
        tmp = numa + numb + jw;
        a[i] = (tmp % 10) + '0';
        jw = tmp / 10;
    }
    if (jw) {
        a[maxlen] = '1';
        reverse(a, maxlen + 1);
    } else
        reverse(a, maxlen);
    printf("%s\n", a);

    return 0;
}