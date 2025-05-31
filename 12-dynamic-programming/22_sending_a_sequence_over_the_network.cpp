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
   while(t--) {
        ll n;
        cin >> n;
        vector<ll> b(n);
        for(int i = 0; i < n; i++) cin >> b[i];

        /*
        
        dp[i][j] => is it possible to construct sequence from an array (0..i) when j no of elements are not in a sequence
        
        dp[i][j] = isTrue(dp[i-1][j+1], j == 0 ? dp[i-arr[i]-1][0] : false, j == arr[i] ? dp[i-1][0] : false)
        
        base: dp[0][0] = true
        
        dp[n][0]
        
        *** This State will give us TLE because n <= 1e5. So we need to minimize the state, can we do this in a single state.

        vector<vector<bool>> dp(n + 1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                bool a = dp[i-1][j+1];
                

                bool c = false;
                if(j == 0 && (i - b[i-1] - 1) >= 0)
                    c = dp[i - b[i - 1] - 1][0];

                bool d = false;
                if(j == b[ i - 1])
                    d = dp[i - 1][0];

                dp[i][j] = a || c || d;
            }
        }

        cout << (dp[n][0] ? "YES" : "NO") << ln;

        */


        /*
            state:
                dp[i] => is it possible to construct sequence a from array(0..i)

            transition: 
                1. segment can be at the right
                2. segment can be at the left
        
        */

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++) {
            // right
            if(i + b[i - 1] <= n && dp[i - 1]) dp[i + b[i - 1]] = true;

            // left
            if(i - b[i - 1] >= 1 && dp[i - b[i - 1] - 1]) dp[i] = true;
        }

        cout << (dp[n] ? "YES" : "NO") << ln;
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