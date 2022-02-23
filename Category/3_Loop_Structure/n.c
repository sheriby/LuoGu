#include <math.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    freopen("n.output.txt", "w", stdout);
    double sqrt5 = sqrt(5);
    for (int n = 0; n <= 48; n++) {
        printf("\"%.2lf\",",
               (pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n)) / sqrt5);
    }
    return 0;
}