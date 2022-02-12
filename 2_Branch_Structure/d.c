#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    printf("%s\n", n < 6 ? "Local" : "Luogu");
    return 0;
}
