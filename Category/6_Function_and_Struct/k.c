#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    long long sum = 0, count = 0;
    while ((scanf("%d", &n)) != EOF) {
        sum += n;
        count++;
    }
    printf("%lld\n", sum * (1 << (count - 1)));
    return 0;
}