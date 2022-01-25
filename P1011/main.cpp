#include <cstdio>
const int MAX = 30;

int ka[MAX]{0};
int kb[MAX]{0};

// 利用数组ka和kb保存方程当中a和b的系数
int main(int argc, char const *argv[]) {
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);

    ka[2] = 1;
    ka[3] = 2;

    for (int i = 4; i < n; i++) {
        ka[i] = ka[i - 2] + ka[i - 1] - 1;
        kb[i] = kb[i - 2] + kb[i - 1] + 1;
    }

    int c = (m - ka[n - 1] * a) / kb[n - 1];
    printf("%d\n", a * ka[x] + c * kb[x]);

    return 0;
}
