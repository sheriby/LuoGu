#include <stdio.h>
#include <string.h>

char str[25];

int reverse(char str[], char buf[], int l, int r) {
    int k = 0, start = 1;
    for (int i = r - 1; i >= l; i--) {
        if (start && str[i] == '0')
            continue;

        buf[k++] = str[i];
        start = 0;
    }
    if (k == 0) {
        buf[k++] = '0';
    }
    buf[k] = '\0';
    return k;
}

int main(int argc, const char *argv[]) {
    scanf("%s", &str);
    int len = strlen(str);
    int mode = 0;
    int pos = -1;
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            mode = 1;
            pos = i;
            break;
        } else if (str[i] == '/') {
            mode = 2;
            pos = i;
            break;
        } else if (str[i] == '%') {
            mode = 3;
            pos = i;
            break;
        }
    }

    char buf1[25];
    char buf2[25];
    switch (mode) {
    case 0:
        reverse(str, buf1, 0, len);
        printf("%s\n", buf1);
        break;
    case 1:
        reverse(str, buf1, 0, pos);
        reverse(str, buf2, pos + 1, len);
        for (int i = strlen(buf2) - 1; i >= 1; i--) {
            if (buf2[i] == '0')
                buf2[i] = '\0';
            else
                break;
        }
        printf("%s.%s\n", buf1, buf2);
        break;
    case 2:
        reverse(str, buf1, 0, pos);
        reverse(str, buf2, pos + 1, len);
        printf("%s/%s\n", buf1, buf2);
        break;
    case 3:
        reverse(str, buf1, 0, pos);
        printf("%s%%", buf1);
        break;
    }
    return 0;
}