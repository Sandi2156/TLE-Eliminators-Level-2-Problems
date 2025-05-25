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

/*
    state:
        dp[i][p][q]:
            Probability to get more heads than tails of prefix array length i,
            where current tossed result is p and no of heads already selected is q

    transition: 0(head) 1(tail)
        dp[i][p][q] = dp[i-1][0][q+1] + (i + 1 + q > n / 2 ? dp[i-1][1][q] : 0)

    base case:
        i == 0 return 0

    result:
        dp[n][0][0] + dp[n][1][0]


*/

long double getProbability(ll i, ll n, ll p, ll q, vector<long double> &probability, vector<vector<vector<long double>>> &dp) {
    if(q + i - 1 <= n / 2) return 0;
    if(i == 1) {
        return (p == 0 ? probability[i - 1] : (1.0 - probability[i - 1]));
    }

    if(dp[i][p][q] != -1) return dp[i][p][q];

    long double prob = p == 0 ? probability[i - 1] : (1.0 - probability[i - 1]);


    long double a = prob * getProbability(i - 1, n, 0, q + 1, probability, dp);
    long double b = 0;
    b = prob * getProbability(i - 1, n, 1, q, probability, dp);

    return dp[i][p][q] = a + b;
}

void solve() {
   ll t = 1;
   while(t--) {
        ll n; cin >> n;
        vector<long double> probability(n);
        for0(i, n) cin >> probability[i];

        vector<vector<vector<long double>>> dp(n+1, vector<vector<long double>>(2, vector<long double>(n+1, -1)));

        cout << getProbability(n, n, 0, 1, probability, dp) + getProbability(n, n, 1, 0, probability, dp) << ln;
   }
   //TC: O(n * n * 2)
   //SC: O(n * n * 2)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}