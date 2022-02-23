#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int y;
    int m;
    int d;
    int id;
} students[100];

bool cmp(const Student &a, const Student &b) {
    if (a.y == b.y && a.m == b.m && a.d == b.d)
        return a.id > b.id;
    if (a.y == b.y && a.m == b.m)
        return a.d < b.d;
    if (a.y == b.y)
        return a.m < b.m;
    return a.y < b.y;
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].y >> students[i].m >>
            students[i].d;
        students[i].id = i;
    }
    sort(students, students + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << students[i].name << endl;
    }
    return 0;
}