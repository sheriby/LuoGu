#include <stdio.h>

char res[1025][1025];

void run(int x, int y, int n) {
    if (n == 1) {
        res[x][y] = ' ';
        res[x][y + 1] = '/';
        res[x][y + 2] = '\\';
        res[x + 1][y] = '/';
        res[x + 1][y + 1] = '_';
        res[x + 1][y + 2] = '_';
        res[x + 1][y + 3] = '\\';
        return;
    }
    int l = 1 << (n - 1);
    run(x, y + l, n - 1);
    run(x + l, y, n - 1);
    run(x + l, y + 2 * l, n - 1);
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    run(0, 0, n);
    int l = 1 << n;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j <= 2 * l; j++) {
            if (j == 2 * l)
                res[i][j] = '\n';
            if (!res[i][j])
                res[i][j] = ' ';
        }
    }

    for (int i = 0; i < l; i++) {
        printf("%s", res[i]);
    }

    return 0;
}