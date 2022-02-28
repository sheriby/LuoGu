#include <stdio.h>
#include <stdlib.h>

int a[10001], len;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 放到最后一步一步冒到最终的位置
void put(int x) {
    len++;
    a[len] = x;
    int b = len;
    // 不断与父结点比较，大了就交换
    while (b != 1 && a[b] < a[b / 2]) {
        swap(&a[b], &a[b / 2]);
        b = b / 2;
    }
}

// 最后一个放到第一个位置，向下一步一步找合适的位置
int get() {
    int x = a[1], c;
    a[1] = a[len];
    len--;
    int f = 1;
    while (f * 2 <= len) {
        // 哪个父结点更小
        if (f * 2 + 1 > len || a[f * 2] < a[f * 2 + 1]) {
            c = f * 2;
        } else {
            c = f * 2 + 1;
        }
        // 和较小的父结点进行交换
        if (a[f] > a[c]) {
            swap(&a[f], &a[c]);
            f = c;
        } else {
            return x;
        }
    }
    return x;
}

int main(int argc, const char *argv[]) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        put(x);
    }
    int ans = 0, tmp;
    while (len > 1) {
        tmp = get() + get();
        put(tmp);
        ans += tmp;
    }

    printf("%d\n", ans);
    return 0;
}