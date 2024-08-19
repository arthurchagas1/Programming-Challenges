#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

bool can_eat_all_pipocas(const vector<int>& P, int C, int T, int mid) {
    int required_competitors = 1;
    int current_sum = 0;
    int max_pipocas = mid * T;
    
    for (int pipoca : P) {
        if (current_sum + pipoca <= max_pipocas) {
            current_sum += pipoca;
        } else {
            required_competitors++;
            current_sum = pipoca;
            if (required_competitors > C) {
                return false;
            }
        }
    }
    
    return true;
}

int minimum_time(int N, int C, int T, const vector<int>& P) {
    int left = (int)ceil((double)*max_element(P.begin(), P.end()) / T);
    int right = accumulate(P.begin(), P.end(), 0) / T;
    if (right * T < accumulate(P.begin(), P.end(), 0)) {
        right++;
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (can_eat_all_pipocas(P, C, T, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int N, C, T;
    cin >> N >> C >> T;
    
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << minimum_time(N, C, T, P) << endl;
    
    return 0;
}
