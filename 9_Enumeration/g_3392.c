#include <stdio.h>

char arr[51][51];
int white[51];
int blue[51];
int red[51];
int s;
int n, m, b;
int minv = 0x7fffffff;

// 搜索
void run(int ind, int c) {
    if (ind == n - 1) {
        if (b && s < minv)
            minv = s;
        return;
    }
    if (c == 0) {
        s += white[ind];
        run(ind + 1, 0);
        b = 1;
        s = s - white[ind] + blue[ind];
        run(ind + 1, 1);
        s -= blue[ind];
    } else if (c == 1) {
        s += blue[ind];
        run(ind + 1, 1);
        s = s - blue[ind] + red[ind];
        run(ind + 1, 2);
        s -= red[ind];
    } else {
        s += red[ind];
        run(ind + 1, 2);
        s -= red[ind];
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 'W')
                white[i]++;
            if (arr[i][j] != 'B')
                blue[i]++;
            if (arr[i][j] != 'R')
                red[i]++;
        }
    }
    s = white[0] + red[n - 1];
    run(1, 0);
    printf("%d\n", minv);
    return 0;
}