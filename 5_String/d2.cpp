#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {
    int n, a, b, sign = 0;
    char buf[1024];
    stringstream stream;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s[0] >= 'a') {
            sign = s[0] - 'a';
            cin >> a >> b;
        } else {
            // 利用stringstream将string转为int
            stream << s;
            stream >> a;
            cin >> b;
        }
        switch (sign) {
        case 0:
            sprintf(buf, "%d+%d=%d", a, b, a + b);
            break;
        case 1:
            sprintf(buf, "%d+%d=%d", a, b, a - b);
            break;
        case 2:
            sprintf(buf, "%d+%d=%d", a, b, a * b);
            break;
        }
        cout << buf << endl << strlen(buf) << endl;
    }
    return 0;
}