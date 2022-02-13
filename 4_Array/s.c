#include <stdio.h>
#include <string.h>

char line[201];
int main(int argc, const char *argv[]) {
    scanf("%s", &line);
    int n = strlen(line);
    printf("%d ", n);
    int mode = 0, cur = 0, start = 1;
    for (int m = 0; m < n; m++) {
        if (!start) {
            scanf("%s", &line);
        } else
            start = 0;
        for (int i = 0; i < n; i++) {
            if (line[i] == mode + '0')
                cur++;
            else {
                printf("%d ", cur);
                mode = !mode;
                cur = 1;
            }
        }
    }
    printf("%d", cur);
    return 0;
}