#include <stdio.h>

int n, k, ans;
int arr[20];

int is_prime(int x) {
    if (x == 1)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void run(int ind, int cnt, int sum) {
    if (cnt == k) {
        if (is_prime(sum))
            ans++;
        return;
    }

    for (int i = ind; i < n; i++) {
        sum += arr[i];
        run(i + 1, cnt + 1, sum);
        sum -= arr[i];
    }
}

int main(int argc, const char *argv[]) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    run(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}