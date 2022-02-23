#include <stdio.h>

int num[80];

int main(int argc, const char *argv[]) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= z; k++) {
                num[i + j + k]++;
            }
        }
    }
    int max = 1, res = 0;
    for (int i = 1; i <= x + y + z; i++) {
        if (num[i] > max) {
            max = num[i];
            res = i;
        }
    }
    printf("%d\n", res);
    return 0;
}