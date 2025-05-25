#include <bits/stdc++.h>  // This will work only for g++ compiler.

#define ln "\n"

using namespace std;
typedef long long ll;

/*

    state:
        dp[i][j] => no of ways I can to back to vertex D if I have j no of steps remaining and standing at ith vertex

    transition:
        dp[i][j] => (dp[pi1][j-1] + dp[pi2][j-1] + dp[pi3][j-1]) % MOD

    base case:
        if j == 1: return i == D

    result: dp[3][n]
    

*/

ll MOD = 1e9+7;

void solve() {
    ll n; cin >> n;

    // vector<vector<ll>> dp(4, vector<ll> (n+1, 0));
    // vector<ll> prev(4, 0);
    ll vertexD = 0, otherVertex = 0;
    // dp[3][0] = 1;
    // prev[3] = 1;
    vertexD = 1;

    for(int j = 1; j <= n; j++) {
        // vector<ll> now(4, 0);
        // for(int i = 0; i < 4; i ++) {
            
            // for(int k = 0; k < 4; k++) {
            //     if(k != i) {
                    // dp[i][j] += dp[k][j - 1];
                    // dp[i][j] %= MOD;

                    // now[i] += prev[k];
                    // now[i] %= MOD;


            //     }
            // }


        // }
        // prev = now;

        ll curVertexD = 3ll * otherVertex;
        ll curOtherVertex = vertexD + 2ll * otherVertex;

        curVertexD %= MOD;
        curOtherVertex %= MOD;

        vertexD = curVertexD;
        otherVertex = curOtherVertex;
    }

    // cout << dp[3][n] << ln;
    // cout << prev[3] << ln;
    cout << vertexD << ln;

   //TC: O(n*2)
   //SC: O(2)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}