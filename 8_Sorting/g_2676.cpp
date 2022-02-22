#include <algorithm>
#include <iostream>
using namespace std;

int h[20001];

int cmp(const int a, const int b) { return a > b; }

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h, h + n, cmp);
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (sum >= b)
            break;
        sum += h[i];
        count++;
    }
    cout << count << endl;
    return 0;
}