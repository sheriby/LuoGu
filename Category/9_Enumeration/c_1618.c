#include <stdio.h>
#include <string.h>

int map[10];
int unique(int x) {
    int a, b, c;
    a = x % 10;
    b = (x / 10) % 10;
    c = (x / 100) % 10;
    return a != b && a != c && b != c && a != 0 && b != 0 && c != 0;
}

int valid(int a, int b, int c) {
    memset(map, 0, sizeof(map));
    while (a) {
        if (map[a % 10])
            return 0;
        map[a % 10]++;
        a /= 10;
    }
    while (b) {
        if (map[b % 10])
            return 0;
        map[b % 10]++;
        b /= 10;
    }
    while (c) {
        if (map[c % 10])
            return 0;
        map[c % 10]++;
        c /= 10;
    }
    return 1;
}

int main(int argc, const char *argv[]) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int flag = 0, x, y, z;
    for (int i = 123; i * c / a <= 987; i++) {
        x = i, y = i * b / a, z = i * c / a;
        if (unique(x) && unique(y) && unique(z) && valid(x, y, z)) {
            flag = 1;
            printf("%d %d %d\n", x, y, z);
        }
    }
    if (!flag)
        printf("No!!!\n");
    return 0;
}