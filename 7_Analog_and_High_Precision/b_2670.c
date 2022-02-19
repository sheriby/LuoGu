#include <stdio.h>

char ans[101][101];

char test(int x, int y) {
    if (ans[x][y] == '*')
        return '*';
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (ans[i][j] == '*')
                count++;
        }
    }
    return count + '0';
}

int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ch = getchar();
            while (ch == '\n' || ch == '\r') {
                ch = getchar();
            }
            ans[i][j] = ch;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", test(i, j));
        }
        printf("\n");
    }
    return 0;
}