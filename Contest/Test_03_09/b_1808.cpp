#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

string words[10001];
set<string> s;

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];
    for (int i = 0; i < n; i++)
        sort(words[i].begin(), words[i].end());
    for (int i = 0; i < n; i++)
        s.insert(words[i]);
    cout << s.size() << endl;
    return 0;
}