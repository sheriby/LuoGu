#include <cstdio>

int main(int argc, char const *argv[]) {
    char num[5];
    scanf("%s", &num);
    for (int i = 4; i >= 0; i--) {
        printf("%c", num[i]);
    }
    return 0;
}
