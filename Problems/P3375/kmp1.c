#include <stdio.h>
#include <string.h>

char str[1000001];
char substr[1000001];
int nxt[1000001];
int len_str, len_substr;

// kmp算法，此处的nxt[j]是前j-1个字符的最大共同前后缀的长度
void get_next() {
    int i = 0, j = -1;
    nxt[0] = -1;
    while (i < len_substr) {
        if (j == -1 || substr[i] == substr[j])
            nxt[++i] = ++j;
        else
            j = nxt[j];
    }
}

void kmp() {
    int i = 0, j = 0;
    while (i < len_str) {
        if (j == -1 || str[i] == substr[j])
            i++, j++;
        else
            j = nxt[j];
        if (j == len_substr) {
            printf("%d\n", i - j + 1);
            j = nxt[j];
        }
    }
}

int main(int argc, const char *argv[]) {
    scanf("%s%s", str, substr);
    len_str = strlen(str), len_substr = strlen(substr);
    get_next();
    kmp();
    for (int i = 1; i <= len_substr; i++) {
        printf("%d ", nxt[i]);
    }
    return 0;
}