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


void solve() {
   ll t = 1;
   cin>>t;
   vll operations(1001, INT_MAX);
    operations[0] = operations[1] = 0;
    for(ll val = 1; val <= 1000; val++) {
        for(ll x = 1; x <= val; x++) {
            ll j = val + (val / x);
            if(j <= 1000) operations[j] = min(operations[j], 1 + operations[val]);
        }
    }
   while(t--) {
        /*
            This is just like knapsack problem. we just convert it to knapsack
        
        */
       ll n, k; cin >> n >> k;
        vll b(n); for0(i, n) cin >> b[i];
        vll c(n); for0(i, n) cin >> c[i];

        k = min(k, 12 * n);
        /*
            dp[i][j] => Maximum no of coins I can earn from an array size i, (0---i) having j operations left

            dp[i][j] => dp[i-1][j], c[i] + dp[i-1][j-operations[b[i]]]
            
            if i == 0
                dp[0][j >= operations[b[0]]] = c[0]

            dp[n-1][k]
        
        */
       vector<vector<ll>> dp(n, vector<ll>(k+1, 0));
       for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                if(i == 0) {
                    if(j >= operations[b[i]]) dp[i][j] = c[i];
                    continue;
                }

                // not pick
                ll noPick = dp[i - 1][j];

                // pick
                ll pick = INT_MIN;
                if(j - operations[b[i]] >= 0) pick = c[i] + dp[i - 1][j - operations[b[i]]];

                dp[i][j] = max(pick, noPick);
            }
       }

       cout << dp[n - 1][k] << ln;
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