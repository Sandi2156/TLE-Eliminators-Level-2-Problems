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

void dfs(ll node, ll parent, vector<map<ll, ll>> &adjList, vll &levelArr, vector<vector<pair<ll, ll>>> &parentGrid, ll level) {
    levelArr[node] = level;

    parentGrid[node][0] = {parent, parent == 0 ? INT_MAX : adjList[node][parent]};
    for(int i = 1; i < t; i++) {
        parentGrid[node][i] = { parentGrid[parentGrid[node][i-1].first][i-1].first, min(parentGrid[node][i-1].second, parentGrid[parentGrid[node][i-1].first][i-1].second) };
    }

    for(auto adjNodePair: adjList[node]) {
        if(adjNodePair.first != parent) {
            dfs(adjNodePair.first, node, adjList, levelArr, parentGrid, level + 1);
        }
    }
}

ll getMinimumPathValue(ll x, ll y, vector<vector<pair<ll, ll>>> &parentGrid, vll &levelArr) {
    if(levelArr[x] < levelArr[y]) return getMinimumPathValue(y, x, parentGrid, levelArr);

    ll ans = INT_MAX, dist = levelArr[x] - levelArr[y];
    for(int i = 0; i < t; i++) {
        if(dist & (1 << i)) {
            ans = min(ans, parentGrid[x][i].second);
            x = parentGrid[x][i].first;
        }
    }

    for(int i = t-1; i >= 0; i--) {
        if(parentGrid[x][i].first != parentGrid[y][i].first) {
            ans = min(ans, parentGrid[x][i].second);
            ans = min(ans, parentGrid[y][i].second);

            x = parentGrid[x][i].first;
            y = parentGrid[y][i].first;
        }
    }

    if(x == y) return ans;
    ans = min(ans, parentGrid[x][0].second);
    ans = min(ans, parentGrid[y][0].second);

    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<map<ll, ll>> adjList(n+1);
    for(int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        // adjList[u].push_back({v, w});
        // adjList[v].push_back({u, w});
        adjList[u][v] = w;
        adjList[v][u] = w;
    }


    vector<vector<pair<ll, ll>>> parentGrid(n+1, vector<pair<ll, ll>>(t, {0, INT_MAX}));
    vll levelArr(n+1, 0);
    dfs(1, 0, adjList, levelArr, parentGrid, 0);

    ll q;
    cin >> q;
    while(q--) {
        ll u, v;
        cin >> u >> v;
        cout << getMinimumPathValue(u, v, parentGrid, levelArr) << ln;
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