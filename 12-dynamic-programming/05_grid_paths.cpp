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
   while(t--) {
        /*
            dp[i][j] => No of paths from i,j to n-1,n-1
            dp[i][j] => dp[i+1][j] + dp[i][j+1]

            base case => when i == n-1 and j == n-1 then return 1

            dp[0][0]
        
        */

        ll n; cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];
        ll MOD = 1e9 + 7;

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(grid[i][j] == '*') {
                    dp[i][j] = 0;
                    continue;
                }
                if(i == n - 1 && j == n - 1) {
                    dp[i][j] = 1;
                    continue;
                }

                // move right
                ll right = 0;
                if(j + 1 < n) {
                    right = dp[i][j + 1];
                }

                // move down
                ll down = 0;
                if(i + 1 < n) {
                    down = dp[i + 1][j];
                }

                dp[i][j] = right + down;
                dp[i][j] %= MOD;
            }
        }

        cout << dp[0][0] << ln;
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