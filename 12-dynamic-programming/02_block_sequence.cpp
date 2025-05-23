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
            1. remove minimum no of elements from the array to make it beautiful. (
                longest beautiful subsequence
            )
            
            2. if a[i] = x and if we decide pick up a[i] as the first element in the block 
               then we will pick up immediate x elements after a[i], that would be the 
               optimal approach

            3. f(i)
               i. consider a[i] as the first element at the block move (i + x) get the longest subsequence => p
               ii. skip the current element move to (i + 1) and get the longest subsequence from (i + 1) => q
               iii. return a[i] + max(f(i + x), f(i + 1))

            
        */

        ll n;
        cin >> n;

        vll arr(n); for0(i, n) cin >> arr[i];

        vector<ll> dp(n+1, 0);
        // dp[i] => max number of elements we can pick from i to n-1 such that 
        // all the blocks are formed with elements from i to n-1
        // dp[i] = max(dp[i+1], 1 + arr[i] + dp[i + arr[i] + 1])
        for(int i = n - 2; i >= 0; i--) {
            // take
            ll x = i + arr[i] + 1 > n ? LLONG_MIN : 1 + arr[i] + dp[i + arr[i] + 1];
            // not take
            ll y = dp[i + 1];

            dp[i] = max(x, y);
        }

        cout << (n - dp[0]) << ln;
   }
   //TC: O(n)
   //SC: O(n)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}