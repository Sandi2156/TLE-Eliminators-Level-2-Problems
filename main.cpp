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


// void solve() {
//    ll t = 1;
//    cin>>t;
//    while(t--) {
//         ll n, k;
//         cin>>n>>k;

//         vll arr(n);
//         for0(i, n) cin>>arr[i];

//         sort(arr.rbegin(), arr.rend());

//         if(arr[0] - arr[n-1] > k+1) cout<<"Jerry"<<ln;
//         else {
//             ll sum = 0;
//             for(auto it: arr) sum += it;
            
//             if(sum & 1) cout<<"Tom"<<ln;
//             else cout<<"Jerry"<<ln;
//         }
//    }

//    /*
//         10 9 1
//         9 9
//         8 9
//         8 8
//         7 8
//         7 7
//         6 7
//         6 6
//         5 6
//         5 5
//         5 4
//         4 4
//         4 3
//         3 3
//         3 2
//         2 2
//         2 1
//         1 1
//         1 0
//         0 0

        
//    */
// }

void solve() {
    /*
    
        gcd -> greatest common divisor
        
    */
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}