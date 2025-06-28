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

bool dfs(int i, int j, int px, int py, vector<string> &grid, vector<vector<bool>> &visited) {
    visited[i][j] = true;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    bool ans = false;
    for(int p = 0; p < 4; p++) {
        int nx = i + dx[p], ny = j + dy[p];

        if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && (nx != px || ny != py) && grid[nx][ny] == grid[i][j]) {
            if(visited[nx][ny]) return true;
            ans = ans || dfs(nx, ny, i, j, grid, visited);
        }
    }

    return ans;
}

void solve() {
    ll n, m; cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool ans = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j]) continue;
            ans = ans || dfs(i, j, -1, -1, grid, visited);
            if(ans) {
                break;
            }
        }
        if(ans) break;
    }

    cout << (ans ? "Yes" : "No") << ln;
   //TC: O(n*m + n*m)
   //SC: O(n*m)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}