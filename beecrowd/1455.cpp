#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

double dist(const Point &a, const Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

Point getCircleCenter(double bx, double by, double cx, double cy) {
    double B = bx * bx + by * by;
    double C = cx * cx + cy * cy;
    double D = bx * cy - by * cx;
    return {(cy * B - by * C) / (2 * D), (bx * C - cx * B) / (2 * D)};
}

Circle circleFrom(const Point &A, const Point &B, const Point &C) {
    Point I = getCircleCenter(B.x - A.x, B.y - A.y, C.x - A.x, C.y - A.y);
    I.x += A.x;
    I.y += A.y;
    return {I, dist(I, A)};
}

Circle circleFrom(const Point &A, const Point &B) {
    Point C = {(A.x + B.x) / 2, (A.y + B.y) / 2};
    return {C, dist(A, B) / 2};
}

bool isInCircle(const Circle &c, const Point &p) {
    return dist(c.center, p) <= c.radius;
}

Circle welzlHelper(vector<Point> &P, vector<Point> R, int n) {
    if (n == 0 || R.size() == 3) {
        if (R.size() == 0) return {{0, 0}, -1};
        if (R.size() == 1) return {R[0], 0};
        if (R.size() == 2) return circleFrom(R[0], R[1]);
        return circleFrom(R[0], R[1], R[2]);
    }

    int idx = rand() % n;
    Point p = P[idx];
    swap(P[idx], P[n - 1]);

    Circle D = welzlHelper(P, R, n - 1);

    if (isInCircle(D, p)) {
        return D;
    }

    R.push_back(p);

    return welzlHelper(P, R, n - 1);
}

Circle welzl(vector<Point> &P) {
    vector<Point> P_copy = P;
    random_shuffle(P_copy.begin(), P_copy.end());
    return welzlHelper(P_copy, {}, P_copy.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, instance = 1;
    while (cin >> n && n != 0) {
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        Circle c = welzl(points);

        cout << "Instancia " << instance++ << "\n";
        cout << fixed << setprecision(2) << c.center.x << " " << c.center.y << " " << c.radius << "\n\n";
    }

    return 0;
}
