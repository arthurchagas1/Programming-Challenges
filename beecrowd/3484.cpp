#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node {
    int height;
    Node* left;
    Node* right;

    Node(int h) : height(h), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int height, int level, map<int, int>& minHeights) {
    if (root == nullptr) {
        root = new Node(height);
        if (minHeights.find(level) == minHeights.end()) {
            minHeights[level] = height;
        } else {
            minHeights[level] = min(minHeights[level], height);
        }
    } else if (height < root->height) {
        insert(root->left, height, level + 1, minHeights);
    } else {
        insert(root->right, height, level + 1, minHeights);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> heights(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    Node* root = nullptr;
    map<int, int> minHeights;

    for (int i = 0; i < N; ++i) {
        insert(root, heights[i], 0, minHeights);
    }

    for (const auto& level : minHeights) {
        cout << level.first << " " << level.second << endl;
    }

    return 0;
}
