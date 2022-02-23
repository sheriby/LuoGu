#include <stdio.h>

int arr[10001];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0, tmp;
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = 0;
                count++;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
        if (flag)
            break;
        flag = 1;
    }
    printf("%d\n", count);
    return 0;
}