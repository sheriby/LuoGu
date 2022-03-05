#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 22;
const int maxm = 2010;
int n, m, a[maxn], ans, tot, ret;
bool drop[maxn], f[maxm];

// 使用dp实现，一组数字可以构成的不同的数字的数目
// f[i][j] = f[i - a[i]][j - 1]
void dp() {
    memset(f, 0, sizeof(f));
    f[0] = true;
    ans = 0;
    tot = 0;
    for (int i = 0; i < n; i++) {
        if (drop[i])
            continue;
        for (int j = tot; j >= 0; j--)
            if (f[j] && !f[j + a[i]])
                f[j + a[i]] = true, ans++;
        tot += a[i];
    }
    ret = max(ans, ret);
}

// 使用dfs来枚举不同的情况
void dfs(int cur, int now) {
    if (now > m)
        return;
    if (cur == n) {
        if (now == m)
            dp();
        return;
    }
    dfs(cur + 1, now);
    drop[cur] = true;
    dfs(cur + 1, now + 1);
    drop[cur] = false;
}

// dfs和dp的结合
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    dfs(0, 0);
    printf("%d\n", ret);
    return 0;
}