#include <cstdio>

int main(int argc, char const *argv[]) {
    unsigned long long n;
    scanf("%llu", &n);
    printf("%llu\n", n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4);
    return 0;
}
