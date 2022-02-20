#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string word, str;

int main(int argc, const char *argv[]) {
    getline(cin, word);
    getline(cin, str);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int len = word.length();
    int first = -1, times = 0, end;
    for (int p = str.find(word); p != -1; p = str.find(word, end + 1)) {
        end = p + len;
        if ((!p || str[p - 1] == ' ') && (!str[end] || str[end] == ' ')) {
            if (first == -1)
                first = p;
            times++;
        }
    }
    if (first != -1)
        cout << times << " " << first << endl;
    else
        cout << -1 << endl;
    return 0;
}