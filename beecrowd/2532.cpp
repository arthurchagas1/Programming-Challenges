#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 10000000;
int n, po, mx = INF, dp[2005][1005];
pair<int,int> balls[1005];

int solve(int points, int idx){
    if(points <= 0) return 0;
    if(idx == n) return INF;
    if(dp[points][idx] != -1) return dp[points][idx];
    return dp[points][idx] = min(balls[idx].second + solve(points - balls[idx].first, idx + 1), solve(points, idx + 1));
}

int main(){
    while(cin >> n >> po){
        memset(dp, -1, sizeof dp);
        
        for(int i = 0; i < n; i++)
            cin >> balls[i].first >> balls[i].second;
        
        int ans = solve(po, 0);
        if(ans != mx) cout << ans << endl;
        else cout << "-1\n";
    }
    return 0;
}
