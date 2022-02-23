#include <cstdio>

int pow2(int x) {
    int count = 0, cur = 1;
    while (cur < x) {
        count++;
        cur <<= 1;
    }
    return count;
}

void print(int num) {
    if (num == 0 || num == 2) {
        printf("%d", num);
        return;
    }
    bool start = true;
    for (int i = pow2(num); i >= 0; i--) {
        if (num & (1 << i)) {
            if (!start) {
                printf("+");
            }
            if (i == 1)
                printf("2");
            else {
                printf("2(");
                print(i);
                printf(")");
            }
            start = false;
        }
    }
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    print(n);
    return 0;
}
