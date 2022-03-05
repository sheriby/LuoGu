#include <bitset>
#include <cstdio>
int w[25];
int table[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
int popcount(unsigned int x) { // 返回x的二进制中1的个数
    int ret = 0;
    for (int i = 0; i < 8; i++)
        ret += table[x & 15], x >>= 4;
    return ret;
}
// 使用bitset实现
int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", w + i);
    // 也是一种遍历
    for (int i = 0, li = 1 << n; i < li; i++) {
        // 这个数有n-m个1，相当于枚举了一种情况
        if (popcount(i) == n - m) {
            std::bitset<2010> S;
            S[0] = 1;
            // 计算能组成多少个不同的数
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    S |= S << w[j];
            int siz = S.count();
            ans = ans > siz ? ans : siz;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}