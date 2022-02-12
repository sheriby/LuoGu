#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    double m, h;
    cin >> m >> h;
    double bmi = m / h / h;
    if (bmi < 18.5)
        cout << "Underweight" << endl;
    else if (bmi < 24)
        cout << "Normal" << endl;
    else
        cout << bmi << endl << "Overweight" << endl;
    return 0;
}
