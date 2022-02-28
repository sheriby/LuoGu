#include <stdio.h>
#include <string.h>

char num[251];
int k;

// 属实离谱的题目，居然不需要考虑0,0在高位就直接忽视的嘛
// 我的评价为：烂
int main(int argc, const char *argv[]) {
    scanf("%s%d", &num, &k);
    int len = strlen(num);
    // int start = 0;
    for (int i = 0; i < len; i++) {
        if (len - i <= k) {
            for (int m = i; m < len; m++) {
                num[m] = -1;
            }
            break;
        }
        // int del = 0;
        for (int j = 1; j <= k; j++) {
            if (num[i] > num[i + j]) {
                // if (!start && num[i + j] == '0' && i + j != len - 1)
                // continue;
                for (int m = i; m < i + j; m++) {
                    num[m] = -1;
                }
                i = i + j - 1;
                k -= j;
                // del = 1;
                break;
            }
        }
        // if (!del)
        // start = 1;
    }
    int flag = 1;
    for (int i = 0; i < len; i++) {
        if (!num[i])
            break;
        if (num[i] == -1 || (num[i] == '0' && flag))
            continue;
        flag = 0;
        printf("%c", num[i]);
    }
    if (flag)
        printf("0\n");

    return 0;
}