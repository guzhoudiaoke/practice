#include <cstdio>
#include <string>
using namespace std;

int an[301];

int main()
{
    int n, total = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &an[i]);
        total += an[i];
    }

    int cur = 0, pre = -1, pos = 0;
    string ans;
    while (cur < total) {
        if (an[pos] > 0) {
            if (pre == pos) {
                if (pos + 1 == n) {
                    ans += "LR";
                }
                else {
                    ans += "RL";
                }
            }
            ans += "P";
            an[pos]--;
            cur++;
            pre = pos;
        }
        else if (pos + 1 < n){
            pos++;
            ans += "R";
        }
    }

    printf("%s\n", ans.c_str());

    return 0;
}
