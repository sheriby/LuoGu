#include <algorithm>
#include <cstdio>
using namespace std;

int arr[5000001];

int main(int argc, const char *argv[]) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    nth_element(arr, arr + k, arr + n);
    printf("%d\n", arr[k]);
    return 0;
}