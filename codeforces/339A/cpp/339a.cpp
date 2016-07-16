#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    cin >> line;

    int count[4] = {0};
    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= '1' && line[i] <= '3') {
            count[line[i] - '0']++;
        }
    }

    string result = "";
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < count[i]; j++) {
            result += (i + '0');
            result += '+';
        }
    }

    //result[result.length() - 1] = '\0';
    result.erase(result.length() - 1);
    cout << result << endl;

    return 0;
}

