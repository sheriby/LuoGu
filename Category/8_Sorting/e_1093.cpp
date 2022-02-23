#include <algorithm>
#include <iostream>
using namespace std;

struct Student {
    int id;
    int yuwen;
    int math;
    int english;
    int sum;
} students[300];

int cmp(const Student &a, const Student &b) {
    if (a.sum == b.sum && a.yuwen == b.yuwen)
        return a.id < b.id;
    if (a.sum == b.sum)
        return a.yuwen > b.yuwen;
    return a.sum > b.sum;
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> students[i].yuwen >> students[i].math >> students[i].english;
        students[i].id = i + 1;
        students[i].sum =
            students[i].yuwen + students[i].math + students[i].english;
    }
    sort(students, students + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << students[i].id << " " << students[i].sum << endl;
    }
    return 0;
}