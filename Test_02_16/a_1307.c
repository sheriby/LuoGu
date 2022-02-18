#include <stdio.h>

// 签到题，数字反转
int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int flag = 0;
    if (n < 0) {
        n = -n;
        flag = 1;
    }
    int ans = 0;
    while (n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    printf("%s%d\n", flag ? "-" : "", ans);
    return 0;
}
