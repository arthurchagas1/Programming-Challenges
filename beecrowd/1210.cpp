#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAX 2002

using namespace std;

int memo[MAX][MAX], pd[MAX][MAX], t[MAX][MAX], c[MAX], v[MAX], n, m, i, p;

int solve(int ano, int idd) {
    if (ano == n + 1) return 0;
    if (memo[ano][idd] != -1) return memo[ano][idd];
    if (idd == m) return memo[ano][idd] = p + c[0] - v[idd] + solve(ano + 1, 1);
    return memo[ano][idd] = min(c[idd] + solve(ano + 1, idd + 1), c[0] + p - v[idd] + solve(ano + 1, 1));
}

int main() {
    _
    while (cin >> n >> i >> m >> p) {
        for (int k = 0; k < m; k++) cin >> c[k];
        for (int k = 1; k <= m; k++) cin >> v[k];

        memset(memo, -1, sizeof(memo));
        memset(t, 0, sizeof(t));

        for (int k = 0; k <= m; k++) pd[n + 1][k] = 0;

        for (int year = n; year >= 1; year--) {
            for (int age = 0; age < m; age++) {
                int keep = c[age] + pd[year + 1][age + 1];
                int sail = p + c[0] - v[age] + pd[year + 1][1];
                if (keep < sail) {
                    pd[year][age] = keep;
                    t[year][age] = 0;
                } else {
                    pd[year][age] = sail;
                    t[year][age] = 1;
                }
            }
            int sail = p + c[0] - v[m] + pd[year + 1][1];
            pd[year][m] = sail;
            t[year][m] = 1;
        }

        cout << pd[1][i] << endl;
        bool first = true;
        for (int age = i, year = 1; year <= n; year++) {
            if (t[year][age]) {
                if (!first) cout << " ";
                cout << year;
                first = false;
                age = 1;
            } else {
                age++;
            }
        }
        if (first) cout << "0";
        cout << endl;
    }
    return 0;
}
