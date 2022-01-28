#include <algorithm>
#include <cstdio>

const int MAX = 31;
int value[MAX];
int v, m;
int min_value;

// 使用最容易想到的回溯法，不过时间复杂度较高，有可能会TLE
void run(int sum = 0, int ind = 1) {
    if (sum > v)
        return;
    min_value = std::min(min_value, v - sum);
    for (int i = ind; i <= m; i++) {
        sum += value[i];
        run(sum, i + 1);
        sum -= value[i];
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d%d", &v, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &value[i]);
    }
    min_value = v;

    run();
    printf("%d\n", min_value);

    return 0;
}
