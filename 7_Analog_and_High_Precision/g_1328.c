#include <stdio.h>

const int rules[5][5] = {{0, -1, 1, 1, -1},
                         {1, 0, -1, 1, -1},
                         {-1, 1, 0, -1, 1},
                         {-1, -1, 1, 0, 1},
                         {1, 1, -1, -1, 0}};
int ta[200];
int tb[200];

int main(int argc, const char *argv[]) {
    int n, na, nb;
    scanf("%d%d%d", &n, &na, &nb);
    for (int i = 0; i < na; i++) {
        scanf("%d", &ta[i]);
    }
    for (int i = 0; i < nb; i++) {
        scanf("%d", &tb[i]);
    }
    int ascore = 0, bscore = 0, res;
    for (int i = 0; i < n; i++) {
        int res = rules[ta[i % na]][tb[i % nb]];
        if (res == 1)
            ascore++;
        else if (res == -1)
            bscore++;
    }

    printf("%d %d\n", ascore, bscore);

    return 0;
}