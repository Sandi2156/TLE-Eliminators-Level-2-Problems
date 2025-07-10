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

map<ll, ll> getMaxTeam(ll n, vll &arr) {
    map<ll, ll> mp;

    for(int i = 0; i < n; i++) {
        int j = upper_bound(arr.begin() + i, arr.end(), arr[i] + 5) - arr.begin();
        mp[i] = j - 1;
    }

    return mp;
}

ll func(ll i, ll k, ll n, map<ll, ll> &mp, vector<vector<ll>> &dp) {
    if(i == n || k == 0) return 0;

    if(dp[i][k] != -1) return dp[i][k];

    // not take
    ll nt = func(i+1, k, n, mp, dp);

    // take
    ll t = (mp[i] - i + 1) + func(mp[i] + 1, k - 1, n, mp, dp);

    return dp[i][k] = max(t, nt);
}

void solve() {
    /*
        dp[i][k] => maximum no of students we can accomodate when I have i...n array and k number of groups remaining

        dp[i][k] => max(dp[i+1][k], p-i+1 + dp[i+p][k-1])

        k == 0 => 0, i == n => 0
    
    */
    ll n, k;
    cin >> n >> k;

    vll arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    map<ll, ll> mp = getMaxTeam(n, arr);
    
    vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
    cout << func(0, k, n, mp, dp) << ln;

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