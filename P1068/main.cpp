#include <algorithm>
#include <iostream>
using namespace std;

struct Student {
    int id;
    int score;
};

bool cmp(Student &a, Student &b) {
    if (a.score < b.score)
        return false;
    if (a.score > b.score)
        return true;
    return a.id < b.id;
}

Student students[5001];

int main(int argc, const char *argv[]) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].score;
    }

    sort(students, students + n, cmp);
    int k = m + (m >> 1);
    int score = students[k - 1].score;
    for (int i = k; i < n; i++) {
        if (students[i].score != score)
            break;
        k++;
    }

    cout << score << " " << k << endl;

    for (int i = 0; i < k; i++) {
        cout << students[i].id << " " << students[i].score << endl;
    }

    return 0;
}