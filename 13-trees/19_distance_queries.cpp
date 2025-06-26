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

ll t = 20;

void dfs(ll node, ll parent, vvll &adjList, vvll &parentGrid, vll &levelArr, ll level) {
    levelArr[node] = level;

    parentGrid[node][0] = parent;
    for(int i = 1; i < t; i++) {
        parentGrid[node][i] = parentGrid[parentGrid[node][i-1]][i-1];
    }

    for(auto adjNode: adjList[node]) {
        if(adjNode != parent) {
            dfs(adjNode, node, adjList, parentGrid, levelArr, level + 1);
        }
    }
} 

ll getLCA(ll x, ll y, vvll &parentGrid, vll &levelArr) {
    if(levelArr[x] < levelArr[y]) return getLCA(y, x, parentGrid, levelArr);

    ll dist = levelArr[x] - levelArr[y];
    for(int i = 0; i < t; i++) {
        if(dist & (1 << i)) x = parentGrid[x][i];
    }

    for(int i = t-1; i >= 0; i--) {
        if(parentGrid[x][i] != parentGrid[y][i]) {
            x = parentGrid[x][i];
            y = parentGrid[y][i];
        }
    }
    return x == y ? x : parentGrid[x][0];
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> adjList(n+1);
    
    for(int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vvll parentGrid(n+1, vll(t, 0));
    vll levelArr(n+1, 0);
    dfs(1, 0, adjList, parentGrid, levelArr, 0);

    while(q--) {
        ll x, y;
        cin >> x >> y;
        ll lcaNode = getLCA(x, y, parentGrid, levelArr);

        cout << (levelArr[x] + levelArr[y] - 2 * levelArr[lcaNode]) << ln;
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