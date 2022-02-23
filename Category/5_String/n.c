#include <stdio.h>
#include <string.h>

char str[256];
int nums[3];

int main(int argc, const char *argv[]) {
    scanf("%s", &str);
    for (int i = 0; i < strlen(str); i += 5) {
        int x = str[i] - 'a';
        if (str[i + 3] >= 'a') {
            nums[x] = nums[str[i + 3] - 'a'];
        } else {
            nums[x] = str[i + 3] - '0';
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%d", nums[i]);
        if (i != 2)
            printf(" ");
    }
    return 0;
}