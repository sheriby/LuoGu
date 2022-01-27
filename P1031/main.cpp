#include <cstdio>

const int MAX = 100;
int num[MAX]{0};

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    int target = sum / n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (num[i] != target) {
            count++;
            int minus = num[i] - target;
            num[i] = target;
            num[i + 1] += minus;
        }
    }
    printf("%d\n", count);
    return 0;
}
