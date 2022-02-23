#include <iostream>
#include <string>
using namespace std;

// 通过递归拼接字符串
string run(int x, int i = 0, string s = "") {
    if (x == 0)
        return "0";
    while (x) {
        if (x & 1)
            s = ((i == 1) ? "2" : "2(" + run(i) + ")") + (s == "" ? "" : "+") +
                s;
        x >>= 1;
        i++;
    }
    return s;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    cout << run(n) << endl;
    return 0;
}
