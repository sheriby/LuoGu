#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string getPre(string mid, string post) {
    int length = mid.length();
    if (length == 1)
        return mid;
    char root = post[length - 1];
    int i = mid.find(root);
    string res(1, root);
    if (i > 0)
        res += getPre(mid.substr(0, i), post.substr(0, i));
    if (i < length - 1)
        res += getPre(mid.substr(i + 1, length - i - 1),
                      post.substr(i, length - i - 1));
    return res;
}

int main(int argc, char const *argv[]) {
    string mid, post;
    cin >> mid >> post;
    cout << getPre(mid, post) << endl;
    return 0;
}
