#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> x, y, dp;
vector<int> id;

bool cw(int a, int b, int c) {
    return ((y[c] - y[a]) * (x[b] - x[a]) < (y[b] - y[a]) * (x[c] - x[a]));
}

bool inside(int pt, int tri) {
    return cw(0, tri, pt) && cw(tri, 1, pt) && cw(1, 0, pt);
}

int main() {
    int n;
    cin >> n;
    n += 2;

    x.resize(n);
    y.resize(n);
    id.resize(n);
    dp.resize(n);

    cin >> x[0];
    y[0] = 0;
    id[0] = 0;

    cin >> x[1];
    y[1] = 0;
    id[1] = 1;

    for (int i = 2; i < n; ++i) {
        id[i] = i;
        cin >> x[i] >> y[i];
    }

    sort(id.begin() + 2, id.end(), [](int a, int b) {
        if (y[a] != y[b]) return y[a] < y[b];
        return x[a] < x[b];
    });

    int res = 0;
    for (int i = 2; i < n; ++i) {
        dp[i] = 1;
        for (int j = 2; j < i; ++j) {
            if (inside(id[j], id[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}
