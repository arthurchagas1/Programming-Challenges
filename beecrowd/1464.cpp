#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
    bool used;

    Point(int x = 0, int y = 0) : x(x), y(y), used(false) {}
};

class OnionLayers {
public:
    void processPoints(const std::vector<Point>& points);
    void printResult() const;

private:
    int countLayers(std::vector<Point>& points);
    int crossProduct(const Point& O, const Point& A, const Point& B) const;
    void markPointsUsed(const std::vector<int>& up, std::vector<Point>& points, int u);

    int layerCount;
};

bool comparePoints(const Point& a, const Point& b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

void OnionLayers::processPoints(const std::vector<Point>& points) {
    std::vector<Point> localPoints = points;
    layerCount = countLayers(localPoints);
}

void OnionLayers::printResult() const {
    if (layerCount % 2 == 0)
        std::cout << "Do not take this onion to the lab!\n";
    else
        std::cout << "Take this onion to the lab!\n";
}

int OnionLayers::countLayers(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), comparePoints);

    int layers = 0;
    int totalUsedPoints = 0;
    int n = points.size();

    while (totalUsedPoints < n) {
        int u = 0;
        std::vector<int> up(n);

        int j = 0;
        while (points[j].used)
            j++;
        int last = j;

        for (; j < n; j++) {
            if (!points[j].used) {
                while (u >= 2 && crossProduct(points[up[u-2]], points[up[u-1]], points[j]) < 0)
                    u--;
                up[u++] = j;
            }
        }

        int t = u + 1;
        for (int i = up[u-1] - 1; i > last; i--) {
            if (!points[i].used) {
                while (u >= t && crossProduct(points[up[u-2]], points[up[u-1]], points[i]) < 0)
                    u--;
                up[u++] = i;
            }
        }

        while (u >= t && crossProduct(points[up[u-2]], points[up[u-1]], points[last]) < 0)
            u--;

        markPointsUsed(up, points, u);
        layers++;
        totalUsedPoints += u;
    }

    return layers;
}

int OnionLayers::crossProduct(const Point& O, const Point& A, const Point& B) const {
    return (B.x - A.x) * (A.y - O.y) - (A.x - O.x) * (B.y - A.y);
}

void OnionLayers::markPointsUsed(const std::vector<int>& up, std::vector<Point>& points, int u) {
    for (int i = 0; i < u; ++i)
        points[up[i]].used = true;
}

int main() {
    int n;

    while (std::cin >> n && n != 0) {
        std::vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> points[i].x >> points[i].y;
        }

        OnionLayers onion;
        onion.processPoints(points);
        onion.printResult();
    }

    return 0;
}
