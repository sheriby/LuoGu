#include <iostream>
#include <string>
#include <vector>
using namespace std;

void str_split(const string &src, const string &sep, vector<string> &vec_str) {
    int start = 0;
    for (int end = src.find(sep, start); end != -1;
         end = src.find(sep, start)) {
        if (end > start) {
            vec_str.push_back(src.substr(start, end - start));
        }
        start = end + sep.size();
    }

    if (start < src.size()) {
        vec_str.push_back(src.substr(start, src.size() - start));
    }
}

int to_int(const string &str) {
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i] > '9')
            break;
        res *= 10;
        res += str[i] - '0';
    }
    return res;
}

string line;
vector<string> strs;
const string sign[3] = {"+", "-", "*"};

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    int mode = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        str_split(line, " ", strs);
        string result = "";
        int flag = 1;
        string left, right;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i][0] >= 'a') {
                mode = strs[i][0] - 'a';
                continue;
            }
            if (flag)
                left = strs[i];
            else
                right = strs[i];
            flag = 0;
        }
        int l = to_int(left), r = to_int(right);
        int ans;
        switch (mode) {
        case 0:
            ans = l + r;
            break;
        case 1:
            ans = l - r;
            break;
        case 2:
            ans = l * r;
            break;
        }
        result =
            to_string(l) + sign[mode] + to_string(r) + "=" + to_string(ans);
        cout << result << endl << result.length() << endl;
        strs.clear();
    }
    return 0;
}
