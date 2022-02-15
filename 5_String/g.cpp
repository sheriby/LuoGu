#include <iostream>
#include <string>
using namespace std;

void lowwer(string &str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

void rtrim(string &str) {
    int i;
    for (i = str.size() - 1; i >= 0; i--) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r' && str[i] != '\t')
            break;
    }
    str.erase(str.begin() + i + 1, str.end());
}

int main(int argc, const char *argv[]) {
    string word, str;
    getline(cin, word);
    getline(cin, str);
    rtrim(str);
    rtrim(word);
    lowwer(str);
    lowwer(word);
    int first = -1, times = 0, end;
    for (int pos = str.find(word); pos != -1; pos = str.find(word, end + 1)) {
        end = pos + word.size();
        if ((pos == 0 || str[pos - 1] == ' ') &&
            (end == str.size() || str[end] == ' ')) {
            if (first == -1)
                first = pos;
            times++;
        }
    }
    if (first != -1)
        cout << times << " " << first << endl;
    else
        cout << -1 << endl;
    return 0;
}