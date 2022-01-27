#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int gcd(int x, int y) {
    if (x < y)
        swap(x, y);
    int tmp;
    while (x % y != 0) {
        tmp = x;
        x = y;
        y = tmp % y;
    }
    return y;
}

int main(int argc, char const *argv[]) {
    int x0, y0;
    scanf("%d%d", &x0, &y0);
    if (y0 % x0 != 0) {
        printf("0\n");
        return 0;
    }
    int count = 0;
    int flag = 0;
    int mul = x0 * y0;
    for (int i = 1; i * x0 <= sqrt(mul); i++) {
        int p = i * x0;
        if ((mul % p == 0) && gcd(p, mul / p) == x0) {
            if (i * x0 == sqrt(mul))
                flag = 1;
            else
                count++;
        }
    }
    printf("%d\n", count * 2 + flag);
    return 0;
}
