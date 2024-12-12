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



void func(int n, int m, vector<vector<int>> &arr, int q, vector<vector<int>> &queries) {
    vector<vector<ll>> prefixSum(n, vector<ll>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            prefixSum[i][j] = arr[i][j] == 0 ? 1: 0;
            if(i > 0) prefixSum[i][j] += prefixSum[i-1][j];
            if(j > 0) prefixSum[i][j] += prefixSum[i][j-1];
            if(i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
        }
    }

    for(int i = 0; i < q; i++) {
        int a = queries[i][0], b = queries[i][1];
        int c = queries[i][2], d = queries[i][3];
        a--,b--,c--,d--;

        long long noOfZeros = prefixSum[c][d];
        if(b > 0) noOfZeros -= prefixSum[c][b-1];
        if(a > 0) noOfZeros -= prefixSum[a-1][d];
        if(a > 0 && b > 0) noOfZeros += prefixSum[a-1][b-1];

        if(noOfZeros > 0) cout<<0<<endl;
        else cout<<1<<endl;
    }
}

void solve() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>arr[i][j];

    int q;
    cin>>q;
    vector<vector<int>> queries(q, vector<int>(4));
    for(int i = 0; i < q; i++)
        for(int j = 0; j < 4; j++)
            cin>>queries[i][j];

    func(n, m, arr, q, queries);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}