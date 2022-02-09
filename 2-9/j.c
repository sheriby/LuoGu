#include <stdio.h>

char isbn[14];

int main(int argc, char const *argv[]) {
    scanf("%s", &isbn);
    int cur = 1, sum = 0;
    for (int i = 0; i < 11; i++) {
        if (isbn[i] == '-')
            continue;
        sum += (isbn[i] - '0') * cur;
        cur++;
    }
    int res = sum % 11;
    if (res == isbn[12] - '0' || res == 10 && isbn[12] == 'X') {
        printf("Right\n");
    } else {
        isbn[12] = res < 10 ? res + '0' : 'X';
        printf("%s\n", isbn);
    }
    return 0;
}
