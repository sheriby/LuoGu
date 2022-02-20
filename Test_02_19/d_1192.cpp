#include <iostream>
using namespace std;

int dp[100001];

int main(int argc, const char *argv[]) {
    int n, k;
    cin >> n >> k;
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= k && i + j <= n; j++) {
            dp[i] = (dp[i] + dp[i + j]) % 100003;
        }
    }
    cout << dp[0] << endl;
    return 0;
}