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

void func(int n, int q, vector<vector<char>> &forest, vvi &queries) {
    vector<vector<int>> prefix(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            prefix[i][j] = forest[i][j] == '*' ? 1 : 0;
            if(i > 0) prefix[i][j] += prefix[i-1][j];
            if(j > 0) prefix[i][j] += prefix[i][j-1];
            if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    for(int i = 0; i < q; i++) {
        int x1 = queries[i][0], y1 = queries[i][1], x2 = queries[i][2], y2 = queries[i][3];
        x1--, y1--, x2--, y2--;

        int ans = prefix[x2][y2];
        if(y1 > 0) ans -= prefix[x2][y1-1];
        if(x1 > 0) ans -= prefix[x1-1][y2];
        if(x1 > 0 && y1 > 0) ans += prefix[x1-1][y1-1];
        cout<<ans<<endl;
    }
}


void solve() {
    int n, q;
    cin>>n>>q;

    vector<vector<char>> forest(n, vector<char>(n));
    for0(i, n) {
        for0(j, n) {
            cin>>forest[i][j];
        }
    }

    vvi queries(q, vi(4));
    for0(i, q) {
        for0(j, 4) {
            cin>>queries[i][j];
        }
    }

    func(n, q, forest, queries);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}