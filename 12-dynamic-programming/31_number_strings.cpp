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

string str = "0100";

ll countStringsWithoutSubsequence(ll i, ll j, ll n, vvll &dp) {
    /*
        dp[i][j] => number of strings [0..i] which doesn't have [0..j] as subsequence

        dp[i][j] => dp[i-1][j] + dp[i-1][j-1]

        if(j < 0) return 0;
        if(i < 0) return 1
    
    */

    if(j < 0) return 0;
    if(i < 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = countStringsWithoutSubsequence(i-1, j, n, dp) + countStringsWithoutSubsequence(i-1, j-1, n, dp);


    /*
        vector<vector<ll>> dp(n+1, vector<ll>(str.size()+1));

        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 1; j <= str.size(); j++) dp[0][j] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= str.size(); j++) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    
    */

}

ll countStringsWithoutSubstring(ll i, ll j, ll n, vvll &dp) {

    /*
        dp[i][j] => number of strings of [0..i] where I have already selected till j-1 th item froms tr

        dp[i][j] => if same selected dp[i-1][j-1] else j == m-1 ? dp[i-1][m-1], j == m-2 ? dp[i-1][m-1], j == m-3 ? dp[i-1][m-3], 
                    if j == m-4 ? dp[i-1][m-1]
                    
        if(j < 0) return 0
        if(i < 0) return 1
    
    */

    if(j < 0) return 0;
    if(i < 1) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = countStringsWithoutSubstring(i-1, j-1, n, dp);
    ll p = 0;
    if(j == str.size()-1 || j == str.size()-3) dp[i][j] += countStringsWithoutSubsequence(i-1, j, n, dp);
    else if(j == str.size()-2 || j == str.size()-4) dp[i][j] += countStringsWithoutSubstring(i-1, j+1, n, dp);

    return dp[i][j];
}


void solve() {
   ll t = 1;
   cin>>t;
   while(t--) {
       
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