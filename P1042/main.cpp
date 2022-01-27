#include <iostream>
#include <string>
using namespace std;

int l[2]{0};
int r[2]{0};
int score[2]{11, 21};
string res[2]{"", ""};

void judge(int i) {
    if (l[i] >= score[i] && l[i] - r[i] >= 2 ||
        r[i] >= score[i] && r[i] - l[i] >= 2) {
        res[i] += std::to_string(l[i]) + ":" + std::to_string(r[i]) + "\n";
        l[i] = 0;
        r[i] = 0;
    }
}

int main(int argc, char const *argv[]) {
    char c;
    while (cin >> c) {
        if (c == 'E')
            break;
        if (c == 'W') {
            l[0]++;
            l[1]++;
        } else {
            r[0]++;
            r[1]++;
        }
        judge(0);
        judge(1);
    }
    cout << res[0];
    cout << l[0] << ":" << r[0] << endl;
    cout << endl;
    cout << res[1];
    cout << l[1] << ":" << r[1] << endl;
    return 0;
}
