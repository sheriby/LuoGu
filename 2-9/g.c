#include <stdio.h>

const int ans[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char const *argv[]) {
    int y, m;
    scanf("%d%d", &y, &m);
    if (m != 2 || !(y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
        printf("%d\n", ans[m]);
    else
        printf("29\n");
    return 0;
}
