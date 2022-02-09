#include <stdio.h>

const int day[8] = {0, 1, 2, 3, 4, 5, 5};

int main(int argc, char const *argv[]) {
    int x, n;
    scanf("%d%d", &x, &n);
    n += x - 1;
    printf("%d\n", ((n / 7) * 5 + day[n % 7] - day[x - 1]) * 250);
    return 0;
}
