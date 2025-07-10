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

ll func(ll i, ll mask, ll n, vector<vector<ll>> &transitions, vector<vector<ll>> &dp) {
    if(i == n) {
        return mask == 0;
    }

    if(dp[i][mask] != -1) return dp[i][mask];

    ll ways = 0;
    for(auto transition: transitions[mask]) {
        ways = (ways + func(i + 1, transition, n, transitions, dp)) % MOD;
    }

    return dp[i][mask] = ways;
}

void generateTransitions(ll i, ll n, ll mask1, ll mask2, vector<vector<ll>> &transitions) {
    if(i > n) return;
    if(i == n) {
        transitions[mask1].push_back(mask2);
        return;
    }

    // if there is alreay one
    generateTransitions(i+1, n, mask1 | (1 << i), mask2, transitions);

    // build 1
    generateTransitions(i+1, n, mask1, mask2 | (1 << i), transitions);

    // build 2
    generateTransitions(i+2, n, mask1, mask2, transitions);
}

void solve() {
    /*
        dp[i][mask] => number of ways we can fill the matrix if I am at index i and the state of current row is mask

        dp[i][mask] => sum(dp[i+1][all mask for possible for current mask])
    
        if(i == n) return mask == 0;
    
    */

    ll n, m;
    cin >> n >> m;

    // m - row, n col
    vector<vector<ll>> transitions(1 << n);
    generateTransitions(0, n, 0, 0, transitions);

    vector<vector<ll>> dp(m + 1, vector<ll>(1 << n, -1));
    cout << func(0, 0, m, transitions, dp) << ln;



   //TC: O(3**n * m + m * 2**n)
   //SC: O(2**n*3**n + m*2**n)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}