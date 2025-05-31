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
            dp[i][prev][second_prev] => minimum no of of chanegs I need to make all the players play logically If my i-1 the 
            player playing at prev and i-2 th player playing at second_prev

            transition
            let's try to place l =>
                if(prev != 0 || second_prev != 0) a = (a[i] == 1) + dp[i+1][0][prev]
            let's try to place r
                if(prev != 1 || second_prev != 1) b = (a[i] == 0) + dp[i+1][1][prev]
            
            if i == n-1
            try to place l
            if((prev != 0 || second_prev != 0) && (prev != 0 && a[0] != 0) && (a[0] != 0 && a[1] != 0)) a = a[i] == 1
            try to place r

            min

            dp[0][p][q]

        */

        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll minFlips = INT_MAX;
        for(int p = 0; p <= 1; p++) { // prev
            for(int q = 0; q <= 1; q++) { // second prev
                vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, 0)));

                for(int i = n-1; i >= 2; i--) {
                    for(int j = 0; j < 2; j++) { // prev
                        for(int k = 0; k < 2; k++) { // second prev
                            if(i == n-1) {
                                // let's try to place l
                                ll left = INT_MAX;
                                if((j != 0 || k != 0) && (j != 0 || q != 0) && (p != 0 || q != 0))
                                    left = (s[n-1] != 'L');
                                // let's try to place r
                                ll right = INT_MAX;
                                if((j != 1 || k != 1) && (j != 1 || q != 1) && (p != 1 || q != 1))
                                    right = (s[n-1] != 'R');
                                
                                dp[i][j][k] = min(left, right);
                            } else {
                                // let's try to place l
                                ll left = INT_MAX;
                                if(j != 0 || k != 0) left = (s[i] != 'L') + dp[i + 1][0][j];
                                // let's try to place r
                                ll right = INT_MAX;
                                if(j != 1 || k != 1) right = (s[i] != 'R') + dp[i + 1][1][j];

                                dp[i][j][k] = min(left, right);
                            }
                        }
                    }
                }

                ll totalFlips = dp[2][p][q] + (p == 0 ? s[1] != 'L' : s[1] != 'R') + (q == 0 ? s[0] != 'L' : s[0] != 'R');

                minFlips = min(minFlips, totalFlips);
            }
        }

        cout << minFlips << ln;
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