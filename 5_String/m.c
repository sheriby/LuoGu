#include <stdio.h>
#include <string.h>

char hui[7];
char dui[7];

int calculate(char a[], int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res *= a[i] - 'A' + 1;
    }
    return res % 47;
}

int main(int argc, const char *argv[]) {
    scanf("%s%s", &hui, &dui);
    if (calculate(hui, strlen(hui)) == calculate(dui, strlen(dui)))
        printf("GO\n");
    else
        printf("STAY\n");
    return 0;
}