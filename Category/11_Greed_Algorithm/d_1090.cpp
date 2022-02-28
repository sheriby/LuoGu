#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d", &n);
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push(x);
    }

    int ans = 0;
    int a, b;
    while (q.size() > 1) {
        a = q.top(), q.pop();
        b = q.top(), q.pop();
        ans += a + b;
        q.push(a + b);
    }
    printf("%d\n", ans);
    return 0;
}