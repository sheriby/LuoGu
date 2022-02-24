#include <stdio.h>
#include <string.h>

char str[31];

int main(int argc, const char *argv[]) {
    scanf("%s", &str);
    int len = strlen(str);
    long long n;
    scanf("%lld", &n);
    long long a = len;
    while (n > 2 * a)
        a *= 2;
    while (n > len) {
        if (n > a) {
            n = (n - a) % (a + 1) - 1;
            if (!n)
                n = a;
        }
        a /= 2;
    }
    printf("%c\n", str[n - 1]);
    return 0;
}