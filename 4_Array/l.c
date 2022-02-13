#include <stdio.h>

int nums[3000];

int main(int argc, const char *argv[]) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int win = 0;
    for (int i = 0; i < m; i++) {
        win += nums[i];
    }
    int min = win;
    for (int i = m; i < n; i++) {
        win = win + nums[i] - nums[i - m];
        if (win < min)
            min = win;
    }
    printf("%d\n", min);
    return 0;
}