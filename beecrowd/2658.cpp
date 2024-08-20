#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int TREESZ = 1 << 18;
const int MOD = 9;

int tree[TREESZ][MOD];
int shift[TREESZ];
int rotate_aux[MOD];
int count_arr[MOD]; 
int from, to, val;

void build(int node, int lo, int hi) {
    shift[node] = 0;

    if (lo == hi) {
        tree[node][1] = 1;
    } else {
        int ls = (node << 1) + 1;
        int rs = ls + 1;
        int mid = (lo + hi) >> 1;

        build(ls, lo, mid);
        build(rs, mid + 1, hi);

        tree[node][1] = hi - lo + 1;
    }
}

void rotate(int* v, int r) {
    r = MOD - r;
    int j = 0;
    for (int i = r; i < MOD; ++i) {
        rotate_aux[j++] = v[i];
    }
    for (int i = 0; i < r; ++i) {
        rotate_aux[j++] = v[i];
    }
    for (int i = 0; i < MOD; ++i) {
        v[i] = rotate_aux[i];
    }
}

void apply_shift(int node, bool is_leaf) {
    if (shift[node] == 0) return;

    if (!is_leaf) {
        int ls = (node << 1) + 1;
        int rs = ls + 1;

        shift[ls] = (shift[ls] + shift[node]) % MOD;
        shift[rs] = (shift[rs] + shift[node]) % MOD;
    }
    rotate(tree[node], shift[node]);
    shift[node] = 0;
}

void get_count(int node, int lo, int hi) {
    apply_shift(node, lo == hi);
    if (from <= lo && hi <= to) {
        if (lo == from) {
            memcpy(count_arr, tree[node], sizeof(count_arr));
        } else {
            for (int i = 0; i < MOD; ++i) count_arr[i] += tree[node][i];
        }
    } else {
        int ls = (node << 1) + 1;
        int rs = ls + 1;
        int mid = (lo + hi) >> 1;

        if (mid >= from) get_count(ls, lo, mid);
        if (mid + 1 <= to) get_count(rs, mid + 1, hi);
    }
}

void lazy_shift(int node, int lo, int hi) {
    apply_shift(node, lo == hi);

    if (hi < from) return;
    if (lo > to) return;

    if (from <= lo && hi <= to) {
        shift[node] = val;
        apply_shift(node, lo == hi);
    } else {
        int ls = (node << 1) + 1;
        int rs = ls + 1;
        int mid = (lo + hi) >> 1;

        lazy_shift(ls, lo, mid);
        lazy_shift(rs, mid + 1, hi);

        for (int i = 0; i < MOD; ++i)
            tree[node][i] = tree[ls][i] + tree[rs][i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    build(0, 0, n - 1);

    while (q-- > 0) {
        cin >> from >> to;

        get_count(0, 0, n - 1);

        val = 0;
        for (int i = 0; i < MOD; ++i) {
            if (count_arr[i] >= count_arr[val]) val = i;
        }

        lazy_shift(0, 0, n - 1);
    }

    for (from = 0; from < n; ++from) {
        to = from;
        get_count(0, 0, n - 1);
        val = 0;
        for (int i = 0; i < MOD; ++i) {
            if (count_arr[i] >= count_arr[val]) val = i;
        }
        cout << val << '\n';
    }

    return 0;
}
