#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string res[20];

bool cmp(const string &a, const string &b) { return a + b > b + a; }

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    sort(res, res + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << res[i];
    }
    return 0;
}