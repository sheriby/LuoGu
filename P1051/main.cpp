#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score1;
    int score2;
    char bgb;
    char xi;
    int papers;

    int scholarship() {
        int ans = 0;
        if (score1 > 80 && papers > 0)
            ans += 8000;
        if (score1 > 85 && score2 > 80)
            ans += 4000;
        if (score1 > 90)
            ans += 2000;
        if (score1 > 85 && xi == 'Y')
            ans += 1000;
        if (score2 > 80 && bgb == 'Y')
            ans += 850;
        return ans;
    }
};

Student students[100];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].score1 >> students[i].score2 >>
            students[i].bgb >> students[i].xi >> students[i].papers;
    }
    string name;
    int max = 0, sum = 0, tmp;
    for (int i = 0; i < n; i++) {
        tmp = students[i].scholarship();
        if (tmp > max) {
            max = tmp;
            name = students[i].name;
        }
        sum += tmp;
    }
    cout << name << endl << max << endl << sum << endl;
    return 0;
}
