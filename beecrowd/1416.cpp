#include <bits/stdc++.h>
using namespace std;
#define INF 4000

class Competition {
public:
    int N, P;
    int time1[109];
    int failed[109];
    vector<int> teams[11];

    void readInput() {
        scanf("%d%d", &N, &P);
    }

    bool hasMoreData() const {
        return N != 0;
    }

    void resetData() {
        for (int i = 0; i <= P; i++) {
            teams[i].clear();
        }
        memset(time1, 0, sizeof(time1));
        memset(failed, 0, sizeof(failed));
    }

    void processTeams() {
        for (int i = 0; i < N; i++) {
            int solved = 0;

            for (int j = 0; j < P; j++) {
                int fails;
                char t[10];
                scanf("%d/%s", &fails, t);
                if (t[0] != '-') {
                    solved++;
                    failed[i] += fails - 1;
                    time1[i] += atoi(t);
                }
            }
            time1[i] += 20 * failed[i];
            teams[solved].push_back(i);
        }
    }

    void calculateAndPrintRange() {
        int wmin = 1, wmax = INF;

        for (int i = 0; i <= P; i++) {
            if (teams[i].empty()) continue;
            sort(teams[i].begin(), teams[i].end(), [this](int a, int b) {
                return time1[a] < time1[b];
            });

            for (int j = 1; j < (int)teams[i].size(); j++) {
                int u = teams[i][j - 1];
                int v = teams[i][j];
                if (failed[u] == failed[v]) continue;
                if (time1[u] == time1[v]) {
                    wmin = wmax = 20;
                } else {
                    while (time1[u] - time1[v] >= (failed[v] - failed[u]) * (wmin - 20)) wmin++;
                    while (time1[u] - time1[v] >= (failed[v] - failed[u]) * (wmax - 20)) wmax--;
                }
            }
        }

        printf("%d", wmin);
        if (wmax == INF) printf(" *\n");
        else printf(" %d\n", wmax);
    }
};

int main() {
    while (true) {
        Competition competition;
        competition.readInput();

        if (!competition.hasMoreData()) break;

        competition.resetData();
        competition.processTeams();
        competition.calculateAndPrintRange();
    }

    return 0;
}
