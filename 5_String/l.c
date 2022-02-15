#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[6];
char str[10];

char *nums[20] = {"one",     "two",       "three",    "four",     "five",
                  "six",     "seven",     "eight",    "nine",     "ten",
                  "eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                  "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(int argc, const char *argv[]) {
    int k = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%s", &str);
        if (str[0] >= 'A' && str[0] <= 'Z')
            str[0] += 32;
        for (int j = 0; j < 20; j++) {
            if (strcmp(str, nums[j]) == 0) {
                num[k++] = ((j + 1) * (j + 1)) % 100;
                break;
            }
        }
        if (strcmp(str, "a") == 0 || strcmp(str, "another") == 0 ||
            strcmp(str, "first") == 0)
            num[k++] = 1;
        else if (strcmp(str, "both") == 0 || strcmp(str, "second") == 0)
            num[k++] = 4;
        else if (strcmp(str, "third") == 0)
            num[k++] = 9;
    }

    qsort(num, k, sizeof(int), cmp);
    printf("%d", num[0]);
    for (int i = 1; i < k; i++) {
        printf("%02d", num[i]);
    }

    return 0;
}