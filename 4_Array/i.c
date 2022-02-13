#include <stdio.h>

char dots[10][5][4] = {{
                           "XXX",
                           "X.X",
                           "X.X",
                           "X.X",
                           "XXX",

                       },
                       {
                           "..X",
                           "..X",
                           "..X",
                           "..X",
                           "..X",
                       },
                       {
                           "XXX",
                           "..X",
                           "XXX",
                           "X..",
                           "XXX",
                       },
                       {
                           "XXX",
                           "..X",
                           "XXX",
                           "..X",
                           "XXX",
                       },
                       {
                           "X.X",
                           "X.X",
                           "XXX",
                           "..X",
                           "..X",
                       },
                       {
                           "XXX",
                           "X..",
                           "XXX",
                           "..X",
                           "XXX",
                       },
                       {
                           "XXX",
                           "X..",
                           "XXX",
                           "X.X",
                           "XXX",
                       },
                       {
                           "XXX",
                           "..X",
                           "..X",
                           "..X",
                           "..X",
                       },
                       {
                           "XXX",
                           "X.X",
                           "XXX",
                           "X.X",
                           "XXX",
                       },
                       {
                           "XXX",
                           "X.X",
                           "XXX",
                           "..X",
                           "XXX",
                       }};

char numstr[101];
int main(int argc, const char *argv[]) {
    int n, num;
    scanf("%d", &n);
    scanf("%s", &numstr);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            num = numstr[j] - '0';
            printf("%s", dots[num][i]);
            if (j != n - 1)
                printf(".");
        }
        printf("\n");
    }
    return 0;
}