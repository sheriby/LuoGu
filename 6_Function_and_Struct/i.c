#include <stdio.h>

typedef struct Student {
    int id;
    int score1;
    int score2;
} Student;

double contemporary(const Student *student) {
    return 0.7 * student->score1 + 0.3 * student->score2;
}

double sum(const Student *student) { return student->score1 + student->score2; }

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    Student s;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s.id, &s.score1, &s.score2);
        if (contemporary(&s) >= 80 && sum(&s) > 140)
            printf("Excellent\n");
        else
            printf("Not excellent\n");
    }
    return 0;
}