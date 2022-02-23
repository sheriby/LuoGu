#include <stdio.h>

int ans[21][21][21];

int main(int argc, char const *argv[]) {
    int x, y, z, q;
    int x1, y1, z1, x2, y2, z2;
    int count = 0;
    scanf("%d%d%d%d", &x, &y, &z, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int xi = x1; xi <= x2; xi++) {
            for (int yi = y1; yi <= y2; yi++) {
                for (int zi = z1; zi <= z2; zi++) {
                    if (ans[xi][yi][zi] == 0) {
                        count++;
                        ans[xi][yi][zi] = 1;
                    }
                }
            }
        }
    }

    printf("%d\n", x * y * z - count);
    return 0;
}
