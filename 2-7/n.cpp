#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int res = 0.2 * a + 0.3 * b + 0.5 * c;
    printf("%d", res);
    return 0;
}
