#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN = 100005;
const int MAXST = MAXN * 4;
typedef long long ll;

vector<ll> monsters(MAXN);
vector<ll> segmentTree(MAXST);

int countDistinctTypes(ll n) {
    return bitset<64>(n).count();
}

void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        segmentTree[node] = monsters[start];
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(2 * node, start, mid);
        buildSegmentTree(2 * node + 1, mid + 1, end);
        segmentTree[node] = segmentTree[2 * node] | segmentTree[2 * node + 1];
    }
}

void updateSegmentTree(int node, int start, int end, int idx, ll newType) {
    if (start == end) {
        monsters[start] = newType;
        segmentTree[node] = newType;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            updateSegmentTree(2 * node, start, mid, idx, newType);
        } else {
            updateSegmentTree(2 * node + 1, mid + 1, end, idx, newType);
        }
        segmentTree[node] = segmentTree[2 * node] | segmentTree[2 * node + 1];
    }
}

ll querySegmentTree(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0LL;
    }
    if (left <= start && end <= right) {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    ll leftQuery = querySegmentTree(2 * node, start, mid, left, right);
    ll rightQuery = querySegmentTree(2 * node + 1, mid + 1, end, left, right);
    return leftQuery | rightQuery;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, m;
    cin >> n >> q >> m;

    for (int i = 1; i <= n; ++i) {
        int monsterType;
        cin >> monsterType;
        monsters[i] = 1LL << monsterType;
    }

    buildSegmentTree(1, 1, n);

    while (q--) {
        int queryType, l, r;
        cin >> queryType >> l >> r;
        if (queryType == 1) {
            cout << countDistinctTypes(querySegmentTree(1, 1, n, l, r)) << "\n";
        } else if (queryType == 2) {
            updateSegmentTree(1, 1, n, l, 1LL << r);
        }
    }

    return 0;
}
