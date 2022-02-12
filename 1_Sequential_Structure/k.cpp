#include <cmath>
#include <cstdio>

int main(int argc, char const *argv[]) {
    int m, t, s;
    scanf("%d%d%d", &m, &t, &s);
    int res = m - (int)ceil(s * 1.0 / t);
    printf("%d\n", res > 0 ? res : 0);
    return 0;
}
