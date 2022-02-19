#include <stdio.h>

char name[100000][11];
int face[100000];

int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%s", &face[i], &name[i]);
    }
    int res = 0, pos, num;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &pos, &num);
        if (face[res] == pos)
            res -= num;
        else {
            res += num;
        }
        res = res % n;
        if (res < 0)
            res += n;
    }
    printf("%s\n", name[res]);
    return 0;
}