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

ll Y = 20;

class LCA {
    private:
        vector<vector<ll>> parentGrid;
        vector<ll> level;
        ll n;
        vector<vector<ll>> adjList;

        void populateParentGrid(ll node, ll parent, ll curLevel) {
            level[node] = curLevel;

            parentGrid[node][0] = parent;
            for(ll i = 1; i < Y; i++) {
                parentGrid[node][i] = parentGrid[parentGrid[node][i-1]][i-1];
            }

            for(ll adjNode: adjList[node]) {
                if(adjNode != parent) {
                    populateParentGrid(adjNode, node, curLevel + 1);
                }
            }
        }
    public:
        LCA(ll n, vvll &adjList) {
            this->n = n;
            this->adjList = adjList;
            parentGrid.assign(n + 1, vector<ll>(Y, 0));
            level.assign(n + 1, 0);

            populateParentGrid(1, 0, 0);
        }

        ll getLCA(ll u, ll v) {
            if(level[v] > level[u]) return getLCA(v, u);

            ll dist = level[u] - level[v];
            for(ll i = 0; i < Y; i++) {
                if(dist & (1 << i)) u = parentGrid[u][i];
            }


            for(ll i = Y - 1; i >= 0; i--) {
                if(parentGrid[u][i] != parentGrid[v][i]) {
                    u = parentGrid[u][i];
                    v = parentGrid[v][i];
                }
            }

            return u == v ? u : parentGrid[u][0];
        }

};


void solve() {
    ll n, q;
    cin >> n >> q;

    vvll adjList(n + 1);
    for(ll i = 2; i <= n; i++) {
        ll u; cin >> u;
        adjList[u].push_back(i);
    }

    LCA lca(n, adjList);
    for(ll i = 1; i <= q; i++) {
        ll a, b;
        cin >> a >> b;

        cout << lca.getLCA(a, b) << ln;
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