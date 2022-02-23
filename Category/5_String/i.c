#include <stdio.h>

char str[101];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d%s", &n, &str);
    int state = 0, change = 0, times = 0;
    int vtimes = 0, ktimes = 0;
    for (int i = 0; i < n; i++) {
        switch (state) {
        case 0:
            if (str[i] == 'V') {
                state = 1;
                vtimes = 1;
            } else {
                ktimes++;
                if (ktimes >= 3)
                    change = 1;
            }
            break;
        case 1:
            if (str[i] == 'K') {
                times++;
                state = 0;
                ktimes = 1;
            } else {
                vtimes++;
                if (vtimes >= 3)
                    change = 1;
            }
            break;
        }
    }
    if ((str[0] == 'K' && str[1] == 'K') ||
        (str[n - 2] == 'V' && str[n - 1] == 'V'))
        change = 1;
    printf("%d\n", times + change);
    return 0;
}