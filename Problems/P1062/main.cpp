#include <cmath>
#include <cstdio>

int main(int argc, char const *argv[]) {
    int k, n;
    scanf("%d%d", &k, &n);
    long long sum = 0;
    for (int i = 0; n; i++, n >>= 1) {
        if (n & 1)
            sum += pow(k, i);
    }
    printf("%lld\n", sum);
    return 0;
}
