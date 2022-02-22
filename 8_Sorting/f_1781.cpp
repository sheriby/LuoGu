#include <algorithm>
#include <iostream>
using namespace std;

struct Person {
    int id;
    string num;
} persons[20];

int cmp(const Person &a, const Person &b) {
    if (a.num.length() == b.num.length())
        return a.num > b.num;
    return a.num.length() > b.num.length();
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> persons[i].num;
        persons[i].id = i + 1;
    }
    sort(persons, persons + n, cmp);
    cout << persons[0].id << endl << persons[0].num << endl;
    return 0;
}