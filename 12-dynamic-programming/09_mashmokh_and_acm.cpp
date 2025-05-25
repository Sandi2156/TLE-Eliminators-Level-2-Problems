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
ll func(ll i, ll k, ll n, vector<vector<ll>> &dp) {
    if(k == 0) return 1;

    if(dp[i][k] != -1) return dp[i][k];

    ll skip = 0;
    if(i + 1 <= n) func(i + 1, k, n, dp);

    ll take = 0;
    for(int t = 1; i * t <= n; t++) {
        take += func(i*t, k-1, n, dp);
        take %= MOD;
    }
    
    return dp[i][k] = (skip + take) % MOD;
}

void solve() {
   ll t = 1;
   while(t--) {
        /*
            dp[i][k] => no of good sequence you can build in the range [i...n] having length k

            Transition:
                dp[i][k] = dp[i+1][k] + sum(dp[multi][k-1])

            Base case:
                k == 0 => 1
                k == 1 => 1

            Result:
                dp[1][k]
        
        */
       ll n, k;
       cin >> n >> k;

       vector<vector<ll>> dp1(n+1, vector<ll>(k+1, -1));

       cout << func(1, k, n, dp1) << ln;


        vector<vector<ll>> dp2(n+1, vector<ll>(k+1, 0));
        for(int i = 0; i <= n; i++) dp2[i][0] = 1;

        // traversing from i = n to 1
        for(int i = n; i >= 1; i--) {
            // length j = 1 to k
            for(int j = 1; j <= k; j++) {
                // if i == n then we can't skip 
                // if i < n then we can skip
                ll skip = 0;
                // if(i + 1 <= n) skip = dp2[i + 1][j];

                ll take = 0;
                for(int p = 1; p * i <= n; p++) {
                    take += dp2[p*i][j-1];
                    take %= MOD;
                }

                dp2[i][j] = (skip + take) % MOD;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                cout << dp1[i][j] << "," << dp2[i][j] << " ";
            } cout << ln;
        }

        // cout << dp1[1][k] << ln;
   }
   //TC: O()
   //SC: O()
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}