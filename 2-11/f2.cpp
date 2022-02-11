#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, ans = 0;
    char x;
    string tmp;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        tmp = to_string(i);
        ans += count(tmp.begin(), tmp.end(), x);
    }
    cout << ans << endl;

    return 0;
}
