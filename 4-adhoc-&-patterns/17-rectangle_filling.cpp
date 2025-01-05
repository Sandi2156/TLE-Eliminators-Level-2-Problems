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
    ll t;
    cin>>t;

    while(t--) {
        ll row, col;
        cin>>row>>col;

        vector<vector<char>> arr(row, vector<char>(col));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin>>arr[i][j];
            }
        }

        ll i, j , k , l , m , n , o , p;
        i = k = m = o = INT_MAX;
        j = l = n = p = INT_MIN;

        for(ll u = 0; u < row; u++) {
            for(ll t = 0; t < col; t++) {
                if(arr[u][t] == 'W') {
                    i = min(i, u);
                    j = max(j, u);
                    k = min(k, t);
                    l = max(l, t);
                } else {
                    m = min(m, u);
                    n = max(n, u);
                    o = min(o, t);
                    p = max(p, t);
                }
            }
        }

        if(i == 0 && j == row-1 && k == 0 && l == col-1) cout<<"YES"<<ln;
        else if(m == 0 && n == row-1 && o == 0 && p == col-1) cout<<"YES"<<ln;
        else cout<<"NO"<<ln;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}