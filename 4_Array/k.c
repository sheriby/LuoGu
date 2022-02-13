#include <stdio.h>
#include <stdlib.h>

int nums[100];
int visit[100];

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    qsort(nums, n, sizeof(int), cmp);
    int count = 0, tmp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = nums[i] + nums[j];
            for (int k = j + 1; k < n; k++) {
                if (visit[k])
                    continue;
                if (tmp == nums[k]) {
                    count++;
                    visit[k] = 1;
                    break;
                }
                if (tmp < nums[k])
                    break;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}