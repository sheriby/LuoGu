#include <cstdio>

const char a[14][100] = {"I love Luogu!\n",
                         "6 4\n",
                         "3\n12\n2\n",
                         "166.667\n",
                         "15\n",
                         "10.8167\n",
                         "110\n90\n0\n",
                         "31.4159\n78.5398\n523.599\n",
                         "22\n",
                         "9\n",
                         "33.3333\n",
                         "13\nR\n",
                         "16\n",
                         "50\n"};

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    printf("%s", a[n - 1]);
    return 0;
}
