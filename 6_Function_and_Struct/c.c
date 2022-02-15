#include <stdio.h>
#define MAX 1500

int is_leap(int x) { return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0); }

int ans[MAX];
int count = 0;

int main(int argc, const char *argv[]) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = x; i <= y; i++) {
        if (is_leap(i))
            ans[count++] = i;
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d", ans[i]);
        if (i != count - 1)
            printf(" ");
    }
    return 0;
}