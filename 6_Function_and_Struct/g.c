#include <stdio.h>
#include <string.h>

typedef struct Student {
    char name[9];
    int yuwen;
    int math;
    int english;
} Student;

Student student;
Student great;

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    int max = -1, sum;
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", &student.name, &student.yuwen, &student.math,
              &student.english);
        sum = student.yuwen + student.math + student.english;
        if (sum > max) {
            strcpy(great.name, student.name);
            great.yuwen = student.yuwen;
            great.math = student.math;
            great.english = student.english;
            max = sum;
        }
    }
    printf("%s %d %d %d\n", great.name, great.yuwen, great.math, great.english);
    return 0;
}