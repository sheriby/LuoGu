#include <cstdio>

long long com(int a, int b) {
    long long res = 1;
    for (int i = 1; i <= b; i++) {
        res *= a--;
        res /= i;
    }
    return res;
}

// 出栈序列有数学公式 C(2n,n)/(n+1)
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", com(2 * n, n) / (n + 1));
    return 0;
}
