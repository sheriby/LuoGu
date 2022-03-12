#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct People {
    string num;
    int id;
} peoples[20];

bool cmp(const People &a, const People &b) {
    if (a.num.size() == b.num.size())
        return a.num < b.num;
    return a.num.size() < b.num.size();
}

int main(int argc, const char *argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> peoples[i].num;
        peoples[i].id = i + 1;
    }
    People *p = max_element(peoples, peoples + n, cmp);
    cout << p->id << endl << p->num << endl;
    return 0;
}