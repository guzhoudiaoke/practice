#include <iostream>
#include <string>
using namespace std;

const int c_num = 5;
const string c_names[c_num] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
    int cur = c_num, x = 1;
    int n;
    cin >> n;
    n--;
    while (n >= cur) {
        n -= cur;
        x *= 2;
        cur = c_num * x;
    }
    cout << c_names[n / x] << endl;

    return 0;
}
