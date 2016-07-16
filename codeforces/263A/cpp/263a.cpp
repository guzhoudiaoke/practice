#include <iostream>
#include <cmath>
using namespace std;

const int c_size = 5;

int main()
{
    int cell[c_size][c_size];
    int row = 0, col = 0;
    for (int i = 0; i < c_size; i++) {
        for (int j = 0; j < c_size; j++) {
            cin >> cell[i][j];
            if (cell[i][j] == 1) {
                row = i;
                col = j;
            }
        }
    }

    int mid = c_size / 2;
    cout << fabs(row - mid) + fabs(col - mid) << endl;
    return 0;
}
