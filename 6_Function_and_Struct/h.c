#include <math.h>
#include <stdio.h>

typedef struct {
    char name[9];
    int yuwen;
    int math;
    int english;
} Student;

Student student[1000];

int main(int argc, const char *argv[]) {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", &student[i].name, &student[i].yuwen, &student[i].math,
              &student[i].english);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(student[i].yuwen - student[j].yuwen) <= 5 &&
                abs(student[i].math - student[j].math) <= 5 &&
                abs(student[i].english - student[j].english) <= 5 &&
                abs(student[i].yuwen + student[i].math + student[i].english -
                    student[j].yuwen - student[j].math - student[j].english) <=
                    10)
                printf("%s %s\n", student[i].name, student[j].name);
        }
    }

    return 0;
}