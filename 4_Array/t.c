#include <stdio.h>

char start[10][11];
char end[10][11];
char tmp[10][11];
int n;

int same(char a[][11], char b[][11]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j])
                return 0;
        }
    }
    return 1;
}

int equal() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            start[i][j] = tmp[i][j];
        }
    }
}

void transform1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = start[n - j - 1][i];
        }
    }
}

void transform2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = start[n - i - 1][n - j - 1];
        }
    }
}

void transform3() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = start[j][n - i - 1];
        }
    }
}

void transform4() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = start[i][n - j - 1];
        }
    }
}

void (*func[4])() = {transform1, transform2, transform3, transform4};

int main(int argc, const char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &start[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", &end[i]);
    }

    int six = same(start, end);

    for (int i = 0; i < 4; i++) {
        (*func[i])();
        if (same(tmp, end)) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    equal();
    for (int i = 0; i < 3; i++) {
        (*func[i])();
        if (same(tmp, end)) {
            printf("5\n");
            return 0;
        }
    }

    if (six) {
        printf("6\n");
        return 0;
    }
    printf("7\n");

    return 0;
}