#include <algorithm>
#include <cstdio>
const int MAX = 5 * 10e3 + 1;

int pos[MAX];

int main(int argc, char const *argv[]) {
    int l, n;
    scanf("%d%d", &l, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    int minTime = 0, maxTime = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i] <= l / 2) {
            minTime = std::max(minTime, pos[i]);
            maxTime = std::max(maxTime, l + 1 - pos[i]);
        } else {
            minTime = std::max(minTime, l + 1 - pos[i]);
            maxTime = std::max(maxTime, pos[i]);
        }
    }
    printf("%d %d\n", minTime, maxTime);
    return 0;
}
