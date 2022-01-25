#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 101;

int n;
char m[MAX]{0};
char tmp[MAX];

bool isHuiwen() {
    int left = 0, right = strlen(m) - 1;
    while (left < right) {
        if (m[left] != m[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int getNum(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1;
}

const char nums[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void add() {
    strcpy(tmp, m);
    int left = 0, right = strlen(m) - 1;

    int jw = 0;
    for (int i = 0; i <= MAX; i++) {
        int numa = 0, numb = 0;
        if (i <= right) {
            numa = getNum(m[i]);
            numb = getNum(tmp[right - i]);
        }

        int ans = numa + numb + jw;
        jw = ans / n;
        m[i] = nums[ans % n];
        if (jw == 0 && i >= right)
            break;
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    int step = 0;
    bool flag = false;
    do {
        if (isHuiwen()) {
            flag = true;
            break;
        }
        add();
        step++;
    } while (step <= 31);
    if (flag)
        cout << "STEP=" << step << endl;
    else
        cout << "Impossible!" << endl;

    return 0;
}
