#include <iostream>
#include <string>
using namespace std;

string str;
string buf;

int main(int argc, const char *argv[]) {
    int n, mode;
    int a, b;
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        cin >> mode;
        switch (mode) {
        case 1:
            cin >> buf;
            str += buf;
            cout << str << endl;
            break;
        case 2:
            cin >> a >> b;
            str = str.substr(a, b);
            cout << str << endl;
            break;
        case 3:
            cin >> a;
            cin >> buf;
            str = str.substr(0, a) + buf + str.substr(a, str.size());
            cout << str << endl;
            break;
        case 4:
            cin >> buf;
            int c = str.find(buf);
            cout << c << endl;
        }
    }
    return 0;
}