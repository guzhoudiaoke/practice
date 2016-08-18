#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct information {
    string name;
    int score;
};

int main()
{
    int n = 0;
    scanf("%d", &n);

    char name[33];
    int score;
    map<string, int> players;
    vector<information> infos;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", name, &score);
        if (players.find(name) == players.end()) {
            players[name] = score;
        }
        else {
            players[name] += score;
        }

        struct information info = {name, score};
        infos.push_back(info);
    }

    vector<string> winners;
    map<string, int>::iterator iter;
    int mmax = -1000001;
    for (iter = players.begin(); iter != players.end(); ++iter) {
        if (iter->second > mmax) {
            mmax = iter->second;
        }
    }
    for (iter = players.begin(); iter != players.end(); ++iter) {
        if (iter->second == mmax) {
            winners.push_back(iter->first);
        }
    }
    players.clear();
    string ans = "";
    for (int i = 0; i < n; i++) {
        string nm = infos[i].name;
        if (players.find(nm) == players.end()) {
            players[nm] = infos[i].score;
        }
        else {
            players[nm] += infos[i].score;
        }
        if (players[nm] >= mmax) {
            vector<string>::iterator it = find(winners.begin(), winners.end(), nm);
            if (it != winners.end()) {
                ans = nm;
                break;
            }
        }
    }

    printf("%s\n", ans.c_str());
}
