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

ll MOD = 998244353;

// ll helper(ll i, ll nextItem, vector<ll> &A, vector<ll> &B, vector<vector<ll>> &dp) {
//     if(i == 0) return 1;

//     if(dp[i][nextItem] != -1) return dp[i][nextItem];

//     ll start = min(nextItem, B[i - 1]);
//     ll ans = 0;
//     while(start >= A[i - 1]) {
//         ans += helper(i - 1, start, A, B, dp);
//         ans %= MOD;
//         start--;
//     }

//     return dp[i][nextItem] = ans;
// }

void solve() {
   ll t = 1;
   while(t--) {
        /*
            dp[i][j] => no of ways I can put value in index i of array size (0 -- i) when I have selected j as a next item

            transition =>
                dp[i][j] = dp[i-1][k1] + dp[i-1][k2] + .... + dp[i-1][kp]

            base case => 
                if i == 0 return 1
        
        */
       ll n; cin >> n;
       vector<ll> A(n), B(n);
       for0(i, n) cin >> A[i];
       for0(i, n) cin >> B[i];

    //    vector<vector<ll>> dp(n + 1, vector<ll>(3002, -1));

    //    cout << helper(n, 3001, A, B, dp) << ln;



        /*
            dp[i][j] => no of ways I can put value in index i of array size (0 -- i) when I have selected j as a current item

            transition =>
                dp[i][j] = dp[i-1][kj-1] + dp[i-1][j-2] + .... + dp[i-1][0]

            base case => 
                if j < A[i] return 0
                if i == 0 then return 1
        
        */
       ll m = 3001;
       vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
       vector<ll> prefixSum(m + 1, 0);

       for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i == 1) {
                    if(j >= A[i - 1] && j <= B[i - 1]) dp[i][j] = 1;
                    continue;
                }
                if(j < A[i - 1] || j > B[i - 1]) {
                    dp[i][j] = 0;
                    // cout << dp[i][j] <<  " ";
                    continue;
                }

                ll ans = 0;
                // for(int k = j; k >= 0; k--) {
                //     ans += dp[i - 1][k];
                //     ans %= MOD;
                // }
                ans = prefixSum[j];

                dp[i][j] = ans;
                // cout << dp[i][j] <<  " ";
            } 
            vector<ll> curPrefixSum(m + 1, 0);
            for(int j = 0; j <= m; j++) {
                if(j == 0) curPrefixSum[j] = dp[i][0];
                else curPrefixSum[j] = dp[i][j] + curPrefixSum[j - 1];
                curPrefixSum[j] %= MOD;
            }

            prefixSum = curPrefixSum;
       }

       ll ans = 0;
       for(int j = m; j >= 0; j--) {
            ans += dp[n][j];
            ans %= MOD;
       }

       cout << ans << ln;
   }
   //TC: O(n*n)
   //SC: O(n*n)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}