#include <stdio.h>

int arr[10001];

// 冒泡排序
int main(int argc, const char *argv[]) {
    int n;
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int tmp;
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                cnt++;
            }
        }
        if (flag)
            break;
    }
    printf("%d\n", cnt);
    return 0;
}