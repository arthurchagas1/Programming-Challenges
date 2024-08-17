#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        bool is_stack = true;
        bool is_queue = true;
        bool is_pq = true;

        for (int i = 0; i < n; ++i) {
            int command, x;
            cin >> command >> x;

            if (command == 1) {
                if (is_stack) s.push(x);
                if (is_queue) q.push(x);
                if (is_pq) pq.push(x);
            } else if (command == 2) {
                if (is_stack) {
                    if (s.empty() || s.top() != x) is_stack = false;
                    else s.pop();
                }
                if (is_queue) {
                    if (q.empty() || q.front() != x) is_queue = false;
                    else q.pop();
                }
                if (is_pq) {
                    if (pq.empty() || pq.top() != x) is_pq = false;
                    else pq.pop();
                }
            }
        }

        if (is_stack + is_queue + is_pq > 1) {
            cout << "not sure" << endl;
        } else if (is_stack) {
            cout << "stack" << endl;
        } else if (is_queue) {
            cout << "queue" << endl;
        } else if (is_pq) {
            cout << "priority queue" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
