#include <stdio.h>

int nums[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int tmp[2222];

int numcount(int a) {
    if (tmp[a])
        return tmp[a];
    int res = 0;
    int k = a;
    while (k) {
        res += nums[k % 10];
        k /= 10;
    }
    tmp[a] = res;
    return res;
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    n -= 4;
    tmp[0] = 6;
    for (int i = 0; i < 1111; i++) {
        for (int j = 0; j <= i; j++) {
            if (numcount(i) + numcount(j) + numcount(i + j) == n) {
                if (i == j)
                    cnt++;
                else
                    cnt += 2;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}