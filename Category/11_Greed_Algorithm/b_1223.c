#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    int time;
    int id;
} Person;

Person persons[1000];

int cmp(const void *a, const void *b) {
    if (((Person *)a)->time == ((Person *)b)->time)
        return (((Person *)a)->id) - (((Person *)b)->id);
    return (((Person *)a)->time) - (((Person *)b)->time);
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &persons[i].time);
        persons[i].id = i + 1;
    }
    qsort(persons, n, sizeof(Person), cmp);
    int t = n - 1;
    double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", persons[i].id);
        ans += (t--) * persons[i].time;
    }
    printf("%d\n%.2lf\n", persons[n - 1].id, ans / n);
    return 0;
}