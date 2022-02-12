#include <stdio.h>
#include <stdlib.h>

int nums[3];
char chars[4];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%s", &chars);
    qsort(nums, 3, sizeof(int), cmp);
    for (int i = 0; i < 3; i++) {
        printf("%d", nums[chars[i] - 'A']);
        if (i != 2)
            printf(" ");
    }
    return 0;
}
