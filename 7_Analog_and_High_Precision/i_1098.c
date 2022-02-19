#include <stdio.h>
#include <string.h>

char str[101];
int ind = 0;
char res[10000];

int legal_letter(char a, char b) {
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && b > a)
        return 1;
    if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && b > a)
        return 1;

    return 0;
}

int main(int argc, const char *argv[]) {
    int p1, p2, p3;
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", &str);
    char *q = str;
    char *p;
    char *cur = str;
    while (p = strstr(q, "-")) {
        char left = *(p - 1), right = *(p + 1);
        if (p - 1 >= cur) {
            if (legal_letter(left, right)) {
                while (cur < p) {
                    res[ind++] = *cur++;
                }
                if (p3 == 1) {
                    left++;
                    while (left < right) {
                        for (int i = 0; i < p2; i++) {
                            if (p1 == 3)
                                res[ind++] = '*';
                            else if (p1 == 1 || left <= '9')
                                res[ind++] = left;
                            else if (p1 == 2)
                                res[ind++] = left - 32;
                        }
                        left++;
                    }
                } else {
                    right--;
                    while (left < right) {
                        for (int i = 0; i < p2; i++) {
                            if (p1 == 3)
                                res[ind++] = '*';
                            else if (p1 == 1 || right <= '9')
                                res[ind++] = right;
                            else if (p1 == 2)
                                res[ind++] = right - 32;
                        }
                        right--;
                    }
                }
                cur = p + 1;
            }
        }
        q = p + 2;
    }
    while (*cur) {
        res[ind++] = *cur++;
    }
    res[ind] = 0;
    printf("%s\n", res);
    return 0;
}