#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    printf("Today, I ate %d apple%s.", n, n > 1 ? "s" : "");
    return 0;
}
