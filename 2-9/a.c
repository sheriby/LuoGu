#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int flag1 = !(n & 1);
    int flag2 = (n > 4) && (n <= 12);
    printf("%d %d %d %d\n", flag1 & flag2, flag1 || flag2, flag1 ^ flag2,
           !flag1 & !flag2);
    return 0;
}
