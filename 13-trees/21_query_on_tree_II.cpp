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


class Tree {
    private:
        ll n;
        vector<map<ll, ll>> adjList;
        vector<ll> distanceList;
        vector<ll> levelList;
        vector<vector<ll>> parentGrid;
        ll p = 20;

        void calculateLevel(ll node, ll parent, vector<map<ll, ll>> &adjList, vector<ll> &levelList, ll level) {
            levelList[node] = level;

            for(auto it: adjList[node]) {
                if(it.first != parent) {
                    calculateLevel(it.first, node, adjList, levelList, 1 + level);
                }
            }
        }

        void calculateDistance(ll node, ll parent, vector<map<ll, ll>> &adjList, vector<ll> &distanceList, ll distance) {
            distanceList[node] = distance;

            for(auto it: adjList[node]) {
                if(it.first != parent) {
                    calculateDistance(it.first, node, adjList, distanceList, distance + it.second);
                }
            }
        }

        void populateParentGrid(ll node, ll parent, auto &adjList, auto &parentGrid) {
            
            parentGrid[node][0] = parent;
            for(int i = 1; i < p; i++) {
                parentGrid[node][i] = parentGrid[parentGrid[node][i-1]][i-1];
            }

            for(auto it: adjList[node]) {
                if(it.first != parent) {
                    populateParentGrid(it.first, node, adjList, parentGrid);
                }
            }
        }

        ll getLCA(ll a, ll b) {
            if(levelList[b] > levelList[a]) return getLCA(b, a);

            ll dist = levelList[a] - levelList[b];
            for(int i = 0; i < p; i++) {
                if(dist & (1 << i)) a = parentGrid[a][i];
            }

            for(int i = p-1; i >= 0; i--) {
                if(parentGrid[a][i] != parentGrid[b][i]) {
                    a = parentGrid[a][i];
                    b = parentGrid[b][i];
                }
            }

            return a == b ? a : parentGrid[a][0];
        }

        ll getKthParent(ll a, ll k) {
            for(int i = 0; i < p; i++) {
                if(k & (1 << i)) a = parentGrid[a][i];
            }

            return a;
        }

    public:
        Tree(ll n, vector<map<ll, ll>> &adjList) {
            this->n = n;
            this->adjList = adjList;
            distanceList.resize(n+1, 0);
            levelList.resize(n+1, 0);
            parentGrid.resize(n+1, vector<ll>(p, 0));

            calculateLevel(1, 0, adjList, levelList, 0);
            calculateDistance(1, 0, adjList, distanceList, 0);
            populateParentGrid(1, 0, adjList, parentGrid);
        }

        ll getDistance(ll a, ll b) {
            ll lca = getLCA(a, b);

            return distanceList[a] + distanceList[b] - 2 * distanceList[lca];
        }

        ll getKthNode(ll a, ll b, ll k) {
            ll lca = getLCA(a, b);

            ll noOfNodesFromAToLCA = levelList[a] - levelList[lca] + 1;

            if(noOfNodesFromAToLCA >= k) return getKthParent(a, k - 1);

            ll noOfNodes = (levelList[a] + 1) + (levelList[b] + 1) - 2 * (levelList[lca] + 1) + 1;
            return getKthParent(b, noOfNodes - k);
        }
};

void solve() {
    ll t;
    cin >> t;

    while(t--) {
        ll n; cin >> n;
        vector<map<ll, ll>> adjList(n + 1);

        for(int i = 1; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;

            adjList[a][b] = c;
            adjList[b][a] = c;
        }

        Tree *tree = new Tree(n, adjList);

        string s;
        cin >> s;
        while(s != "DONE") {
            if(s == "DIST") {
                ll a, b; cin >> a >> b;
                cout << tree->getDistance(a, b) << ln;
                
            } else if (s == "KTH") {
                ll a, b, k; cin >> a >> b >> k;
                cout << tree->getKthNode(a, b, k) << ln;
            }
            cin >> s;
        }
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