#include <iostream>
#include <stack>
#include <string>
using namespace std;

string expression;
stack<int> stk;
int l, r, a, b;
char ch;

int to_int() {
    int ans = 0;
    for (int i = l; i < r; i++) {
        ans *= 10;
        ans += expression[i] - '0';
    }
    return ans;
}

int main(int argc, const char *argv[]) {
    cin >> expression;
    for (int i = 1; i < expression.size(); i++) {
        ch = expression[i];
        if (ch == '@')
            break;
        if (ch == '.') {
            r = i;
            stk.push(to_int());
            l = -1;
        } else if (l == -1 && ch >= '0' && ch <= '9') {
            l = i;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            b = stk.top(), stk.pop();
            a = stk.top(), stk.pop();
            switch (ch) {
            case '+':
                stk.push(a + b);
                break;
            case '-':
                stk.push(a - b);
                break;
            case '*':
                stk.push(a * b);
                break;
            case '/':
                stk.push(a / b);
                break;
            }
        }
    }
    cout << stk.top() << endl;
    return 0;
}