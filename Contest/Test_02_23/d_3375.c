#include <stdio.h>
#include <string.h>

char s1[1000001];
char s2[1000001];
int nxt[1000001];
int len1;
int len2;

void get_next() {
    int t1 = 0, t2;
    nxt[0] = t2 = -1;
    while (t1 < len2) {
        if (t2 == -1 || s2[t1] == s2[t2])
            nxt[++t1] = ++t2;
        else
            t2 = nxt[t2];
    }
}

void kmp() {
    int t1 = 0, t2 = 0;
    while (t1 < len1) {
        if (t2 == -1 || s1[t1] == s2[t2]) {
            t1++;
            t2++;
        } else
            t2 = nxt[t2];
        if (t2 == len2) {
            printf("%d\n", t1 - len2 + 1);
            t2 = nxt[t2];
        }
    }
}

// KMP算法
int main(int argc, const char *argv[]) {
    scanf("%s", &s1);
    scanf("%s", &s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    get_next();
    kmp();
    for (int i = 1; i <= len2; i++) {
        printf("%d ", nxt[i]);
    }
    return 0;
}