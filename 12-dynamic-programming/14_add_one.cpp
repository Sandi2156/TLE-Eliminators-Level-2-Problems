#include <bits/stdc++.h>  // This will work only for g++ compiler.

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based

// short hand for usual tokens
#define pb push_back
#define fi first
#define se second
#define ln "\n"

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() // Forward traversal
#define rall(x) (x).rbegin, (x).rend() // Reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

// find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ll MOD = 1e9 + 7;

// ll helper(ll n, ll m, map<pair<ll, ll>, ll> &dp) {
//     if(m == 0) {
//         ll size = 0;
//         while(n > 0) {
//             n /= 10;
//             size++;
//         }

//         return size;
//     }

//     if(dp.find({n, m}) != dp.end()) return dp[{n, m}];

//     ll len = 0;
//     while(n > 0) {
//         ll digit = n % 10;

//         len += helper(digit + 1, m - 1, dp);
//         len %= MOD;

//         n /= 10;
//     }
    
//     return dp[{n, m}] = len;
// }

// void solve() {
//    ll t = 1;
//    cin>>t;
//    while(t--) {
//         /*
//             state: dp[digit][i] => length of the digit when we have i operations left

//             transition: dp[digit][i] => (dp[1stdigit][i-1] + dp[2nddigit][i-1] + .... + dp[lastdigit][i-1]) % MOD

//             base case: if i == 0: return len(dight)

//             answer: dp[1stdigit][n] + .... + 
        
//         */
//        ll n, m; cin >> n >> m;

//        // recursion
//         // map<pair<ll, ll>, ll> dp;
//         // cout << helper(n, m, dp) << ln;

//         // Tabulation
//         // vector<vector<ll>> dp(10, vector<ll>(m+1, 0));
//         // for(int i = 0; i < 10; i++) dp[i][0] = 1;

//         // for(int j = 1; j <= m; j++) {
//         //     for(int i = 0; i < 10; i++) {
//         //         if(i == 9) {
//         //             dp[i][j] = dp[0][j - 1] + dp[1][j - 1];
//         //         } else {
//         //             dp[i][j] = dp[i + 1][j - 1];
//         //         }
//         //         dp[i][j] %= MOD;
//         //     }
//         // }

//         // ll ans = 0;
//         // while(n > 0) {
//         //     int digit = n % 10;
//         //     ans += dp[digit][m];
//         //     ans %= MOD;
//         //     n /= 10;
//         // }

//         // cout << ans << ln;
//    }
//    //TC: O()
//    //SC: O()
// }


void solve() {
    ll precomputeM = 2 * 1e5;
    vector<vector<ll>> dp(10, vector<ll>(precomputeM+1, 0));
    for(int i = 0; i < 10; i++) dp[i][0] = 1;

    for(int j = 1; j <= precomputeM; j++) {
        for(int i = 0; i < 10; i++) {
            if(i == 9) {
                dp[i][j] = dp[0][j - 1] + dp[1][j - 1];
            } else {
                dp[i][j] = dp[i + 1][j - 1];
            }
            dp[i][j] %= MOD;
        }
    }


    ll t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;

        ll ans = 0;
        while(n > 0) {
            int digit = n % 10;
            ans += dp[digit][m];
            ans %= MOD;
            n /= 10;
        }

        cout << ans << ln;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}