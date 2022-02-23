#include <stdio.h>

int main(int argc, const char *argv[]) {
    int n;
    char name[20];
    int age, score;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d", &name, &age, &score);
        score += score / 5;
        printf("%s %d %d\n", name, age + 1, score > 600 ? 600 : score);
    }
    return 0;
}