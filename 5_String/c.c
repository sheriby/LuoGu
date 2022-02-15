#include <stdio.h>

char str[100];
int map[26];

int is_prime(int x) {
    if (x == 0 || x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, const char *argv[]) {
    int max = -1, min = 0x7fffffff;
    scanf("%s", &str);
    char *p = str;
    while (*p) {
        map[*p - 'a']++;
        p++;
    }

    for (int i = 0; i < 26; i++) {
        if (!map[i])
            continue;
        if (map[i] > max)
            max = map[i];
        if (map[i] < min)
            min = map[i];
    }

    if (is_prime(max - min))
        printf("Lucky Word\n%d\n", max - min);
    else
        printf("No Answer\n0\n");

    return 0;
}