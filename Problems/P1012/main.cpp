#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

string num[MAX];

// 巧妙的利用字符串排序
bool cmp(string a, string b) { return a + b > b + a; }

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << num[i];
    }
    cout << endl;
    return 0;
}
