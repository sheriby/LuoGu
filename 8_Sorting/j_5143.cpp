#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    int z;
} points[50000];

bool cmp(const Point &a, const Point &b) { return a.z < b.z; }

double dis(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main(int argc, const char *argv[]) {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    double s = 0;
    sort(points, points + n, cmp);
    for (int i = 0; i < n - 1; i++) {
        s += dis(points[i], points[i + 1]);
    }
    printf("%.3lf\n", s);
    return 0;
}