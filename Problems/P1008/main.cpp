#include <cstdio>

bool unique(int num) {
    int a = num % 10;
    if (a == 0)
        return false;

    int b = (num / 10) % 10;
    if (b == 0)
        return false;

    int c = (num / 100) % 10;
    if (c == 0)
        return false;

    return (a != b) && (a != c) && (b != c);
}

bool isResult(int num) {
    int nums[10]{0};
    int tmp;
    for (int i = 1; i <= 3; i++) {
        tmp = num * i;
        while (tmp) {
            int i = tmp % 10;
            if (nums[i])
                return false;
            nums[i] = 1;
            tmp /= 10;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    for (int i = 123; i < 333; i++) {
        if (!unique(i) || !unique(2 * i) || !unique(3 * i))
            continue;
        if (isResult(i)) {
            printf("%d %d %d\n", i, 2 * i, 3 * i);
        }
    }
    return 0;
}
