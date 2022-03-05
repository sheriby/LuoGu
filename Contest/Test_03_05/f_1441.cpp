#include <cstdio>
#include <map>
using namespace std;

int arr[21];
int n, m;
map<pair<int, int>, int> maps;
map<int, int> ress;

void run(int ind, int sum, int rem, int tag) {
    if (n - ind < rem)
        return;
    if (ind == n) {
        if (!rem && sum && !maps[make_pair(tag, sum)]) {
            maps[make_pair(tag, sum)]++;
            ress[tag]++;
        }
        return;
    }
    if (rem) {
        run(ind + 1, sum, rem - 1, tag * 20 + ind);
    }
    run(ind + 1, sum, rem, tag);
    run(ind + 1, sum + arr[ind], rem, tag);
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    run(0, 0, m, 0);
    int max = -1;
    for (map<int, int>::iterator it = ress.begin(); it != ress.end(); it++) {
        if (it->second > max) {
            max = it->second;
        }
    }
    printf("%d\n", max);
    return 0;
}