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

ll func(ll i, ll j, ll mask, vvll &points, vector<vector<ll>> &dp) {
    ll n = points.size();
    if(i == n) return 0;

    if(dp[j][mask] != -1) return dp[j][mask];

    ll minDistance = INT_MAX;
    for(int k = 0; k < n; k++) {
        if((mask & (1 << k)) == 0) {
            ll dis = abs(points[k][0] - points[j][0]) + abs(points[k][1] - points[j][1]);
            minDistance = min(minDistance, (i != 0 ? dis : 0) + func(i + 1, k, mask + (1 << k), points, dp));
        }
    }

    return dp[j][mask] = minDistance;
}

void solve() {
    ll n;
    cin >> n;

    vector<vector<ll>> points;
    for(int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    vector<vector<ll>> dp(n, vector<ll>(1 << n + 1, -1));
    cout << func(0, 0, 0, points, dp) << ln;

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