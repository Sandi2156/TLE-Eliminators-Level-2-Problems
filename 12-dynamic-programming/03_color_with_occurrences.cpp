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
        /*
            state:
                dp[i][k] => minimum no of operatios required to color all of the 
                    characters from i -> n-1 where k characters in the prefix
                    are already colored.

            dp[i][k]:
                min(dp[i+1][k-1] if k >= 1, min(d[i+1][max(k-1, sj-1)] for all s))

            solution: dp[0][0]
        */

        string s; cin >> s;
        ll n; cin >> n;
        vector<string> colorStrings(n); for0(i, n) cin >> colorStrings[i];

        vector<vector<ll>> dp(s.length(), vector<ll>(s.length(), INT_MAX));

        for(int i = s.length() - 1; i >= 0; i--) {
            for(int k = 0; k < s.length(); k++) {

                // invalid state
                if(i + k > s.length()) {
                    dp[i][k] = INT_MAX;
                    continue;
                }

                // base
                if(i + k == s.length()) {
                    dp[i][k] = 0;
                    continue;
                }

                // skip
                ll skip = INT_MAX;
                if(k > 0) {
                    skip = dp[i + 1][k - 1];
                }

                // place string
                ll take = INT_MAX;
                for(auto colorString: colorStrings) {
                    if(i + colorString.length() > s.length()) continue;

                    bool matched = true;
                    int p = i, q = 0;
                    while(q < colorString.length()) {
                        if(s[p] != colorString[q]) {
                            matched = false;
                            break;
                        }
                        p++,q++;
                    }

                    if(matched) {
                        take = min(take, 1 + (i == s.length() - 1 ? 0 : dp[i + 1][max((ll)(k - 1), (ll)(colorString.length()-1))]));
                    }
                }

                dp[i][k] = min(skip, take);
            }
        }

        cout << (dp[0][0] ==  INT_MAX ? -1 : dp[0][0]) << ln;

        /*
            baca
            3
            a
            c
            b

            4*4

            3,0
            
        
        */
   }
   //TC: O(len(s) * len(s) * n * max_len(sj))
   //SC: O(len(s) * len(s))
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}