#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m, a;
    scanf("%d %d", &n, &m);

    set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        s.insert(a);
    }

    int sum = 0;
    int cur = 1;
    vector<int> v;
    while (1) {
        if (cur + sum > m) {
            break;
        }
        if (s.find(cur) != s.end()) {
            cur++;
            continue;
        }
        v.push_back(cur);
        sum += cur;
        cur++;
    }
    printf("%u\n", v.size());
    for (unsigned int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
