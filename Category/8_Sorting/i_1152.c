#include <math.h>
#include <stdio.h>

int arr[1001];
int map[1001];

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int minus;
    for (int i = 0; i < n - 1; i++) {
        minus = abs(arr[i + 1] - arr[i]);
        if (minus == 0 || minus >= n) {
            printf("Not jolly\n");
            return 0;
        }
        map[minus] = 1;
    }
    int flag = 1;
    for (int i = 1; i < n; i++) {
        if (!map[i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Jolly\n");
    else
        printf("Not jolly\n");
    return 0;
}