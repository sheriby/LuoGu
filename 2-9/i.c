#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n, a, b, min_val = 0x7fffffff, val;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &a, &b);
        val = ceil(n * 1.0 / a) * b;
        if (val < min_val)
            min_val = val;
    }
    printf("%d\n", min_val);
    return 0;
}
