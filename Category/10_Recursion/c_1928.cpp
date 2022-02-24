#include <iostream>
#include <string>
using namespace std;

string parse(const string &s);

string run(const string &s) {
    string res = "";
    int left = -1, start = 0, flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            if (left == -1)
                left = i;
            flag++;
        }
        if (s[i] == ']') {
            if (--flag == 0) {
                res += s.substr(start, left - start) +
                       parse(s.substr(left + 1, i - left - 1));
                start = i + 1;
                left = -1;
            }
        }
    }
    if (start < s.size())
        res += s.substr(start, s.size() - start);
    return res;
}

string parse(const string &s) {
    int num = 0, ind = 1;
    if (s[1] >= '0' && s[1] <= '9') {
        ind = 2;
        num = s[1] - '0' + 10 * (s[0] - '0');
    } else {
        num = s[0] - '0';
    }
    string res = "";
    string t = run(s.substr(ind, s.size() - ind));
    for (int i = 0; i < num; i++) {
        res += t;
    }
    return res;
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;
    cin >> str;
    string res = run(str);
    cout << res << endl;
    return 0;
}