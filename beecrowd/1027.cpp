#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int N;

    while (cin >> N) {
        vector<Point> points(N);

        for (int i = 0; i < N; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
        });

        vector<int> dp1(N, 1);  // dp1[i]: max sequence ending at i with y = a+1
        vector<int> dp2(N, 1);  // dp2[i]: max sequence ending at i with y = a-1

        int maxPoints = 1;

        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (points[i].x != points[j].x) {
                    if (points[i].y == points[j].y + 2) {
                        dp1[i] = max(dp1[i], dp2[j] + 1);
                    }
                    if (points[i].y == points[j].y - 2) {
                        dp2[i] = max(dp2[i], dp1[j] + 1);
                    }
                }
            }
            maxPoints = max({maxPoints, dp1[i], dp2[i]});
        }

        cout << maxPoints << endl;
    }

    return 0;
}
