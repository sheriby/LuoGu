#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    printf("%d\n", n % 4 == 0 && n % 100 != 0 || n % 400 == 0);
    return 0;
}
