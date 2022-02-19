#include <algorithm>
#include <cstdio>
#include <cstring>

typedef struct Person {
    char name[31];
    char post[10];
    int bangg;
    int level;
    int step;
} Person;
Person persons[110];

const char *posts[10] = {"BangZhu", "FuBangZhu", "HuFa",     "ZhangLao",
                         "TangZhu", "JingYing",  "BangZhong"};
int num[7] = {0, 0, 2, 4, 7, 25, 10000};

int cmp1(Person &a, Person &b) {
    if (a.bangg > b.bangg)
        return true;
    if (a.bangg < b.bangg)
        return false;
    return a.step < b.step;
}
int cmp2(Person &a, Person &b) {
    int post1, post2;
    for (int i = 0; i < 7; i++) {
        if (strcmp(a.post, posts[i]) == 0)
            post1 = i;
        if (strcmp(b.post, posts[i]) == 0)
            post2 = i;
    }
    if (post1 < post2)
        return true;
    if (post1 > post2)
        return false;
    if (a.level > b.level)
        return true;
    if (a.level < b.level)
        return false;
    return a.step < b.step;
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s%d%d", &persons[i].name, &persons[i].post, &persons[i].bangg,
              &persons[i].level);
        persons[i].step = i;
    }

    std::sort(persons, persons + n, cmp1);
    for (int i = 0; i < n; i++) {
        int p;
        for (int j = 0; j < 7; j++) {
            if (strcmp(persons[i].post, posts[j]) == 0) {
                p = j;
                break;
            }
        }
        if (p < 2)
            continue;
        for (int k = 2; k < 7; k++) {
            if (num[k] > 0) {
                strcpy(persons[i].post, posts[k]);
                num[k]--;
                break;
            }
        }
    }
    std::sort(persons, persons + n, cmp2);
    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", persons[i].name, persons[i].post,
               persons[i].level);
    }
    return 0;
}