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

ll func(ll i, ll j, vll &arr, vvll &dp) {
    /*
        It comes under L..R DP

        dp[i][j] => Minimum number of seconds needed to delete substring i...j

        dp[i][j] => min {
            - 1 + dp[i+1][j] => when we delete a single item
            - min(dp[i+1][k-1]) => when arr[i] matches with arr[k]. The idea is we can delete this arr[i] and arr[k] with 
                                    the last delete of substring i+1...k-1
            - 1 + dp[i+2][j] when arr[i] == arr[i+1]
        }

        i == j => 1
        i > j => 0
    
    */

    if(i == j) return 1;
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    ll a = 1 + func(i + 1, j, arr, dp);
    ll b = 1e9;
    for(int k = i+2; k <= j; k++) {
        if(arr[i] == arr[k]) b = min(b, func(i + 1, k - 1, arr, dp) + func(k + 1, j, arr, dp));
    }
    ll c = 1e9;
    if(i+1 < arr.size() && arr[i] == arr[i+1]) c = 1 + func(i + 2, j, arr, dp);

    // cout << i << " " << j << " " << a << " " << b << " " << c << ln; 

    return dp[i][j] = min(a, min(b, c));
}

void solve() {
    ll n;
    cin >> n;

    vll arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vvll dp(n, vll(n, -1));

    cout << func(0, n-1, arr, dp) << ln;

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