#include <cmath>
#include <cstdio>

const int MAX = 20;
int num[MAX]{0};
int n, k, result;

bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void run(int sum = 0, int ind = 0, int count = 0) {
    if (count == k) {
        if (isPrime(sum))
            result++;
        return;
    }
    for (int i = ind; i < n; i++) {
        sum += num[i];
        run(sum, i + 1, count + 1);
        sum -= num[i];
    }
}

int main(int argc, char const *argv[]) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    run();
    printf("%d\n", result);

    return 0;
}
