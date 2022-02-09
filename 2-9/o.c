#include <stdio.h>
#include <stdlib.h>

int bian[3];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &bian[i]);
    }
    qsort(bian, 3, sizeof(int), cmp);
    if (bian[0] + bian[1] <= bian[2]) {
        printf("Not triangle\n");
    } else {
        int l = bian[0] * bian[0] + bian[1] * bian[1], r = bian[2] * bian[2];
        if (l > r)
            printf("Acute triangle\n");
        else if (l == r)
            printf("Right triangle\n");
        else
            printf("Obtuse triangle\n");

        if (bian[0] == bian[1] || bian[1] == bian[2]) {
            printf("Isosceles triangle\n");
            if (bian[0] == bian[2])
                printf("Equilateral triangle\n");
        }
    }

    return 0;
}
