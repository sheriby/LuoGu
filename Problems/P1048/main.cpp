#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 经典的动态规划：01背包问题
int main(int argc, char const *argv[]) {
    int t, m;
    cin >> t >> m;
    vector<int> value(m + 1, 0);
    vector<int> weight(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> dp(m + 1, vector<int>(t + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= t; j++) {
            int value_with = (j - weight[i] >= 0)
                                 ? (value[i] + dp[i - 1][j - weight[i]])
                                 : 0;
            int value_without = dp[i - 1][j];
            dp[i][j] = max(value_with, value_without);
        }
    }

    cout << dp[m][t] << endl;
    return 0;
}
