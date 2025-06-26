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
        vector<vector<ll>> adjList;
        ll n;
        vector<vector<ll>> parentGrid;
        vector<ll> levelArr;
        ll parentsPower = 20;

        void populateParentGrid(ll node, ll parent, ll level) {
            levelArr[node] = level;

            parentGrid[node][0] = parent;
            for(int i = 1; i < parentsPower; i++) {
                parentGrid[node][i] = parentGrid[parentGrid[node][i-1]][i-1];
            }

            for(auto adjNode: adjList[node]) {
                if(adjNode != parent) {
                    populateParentGrid(adjNode, node, 1 + level);
                }
            }
        }
        
        ll getLCA(ll a, ll b) {
            if(levelArr[b] > levelArr[a]) return getLCA(b, a);
    
            ll diff = levelArr[a] - levelArr[b];
            for(int i = 0; i < parentsPower; i++) {
                if(diff & (1 << i)) a = parentGrid[a][i];
            }
    
            for(int i = parentsPower-1; i >= 0; i--) {
                if(parentGrid[a][i] != parentGrid[b][i]) {
                    a = parentGrid[a][i];
                    b = parentGrid[b][i];
                }
            }
    
            return a == b ? a : parentGrid[a][0];
        }
    
        ll dfsPrefixSum(ll node, ll parent, vector<ll> &differenceArr, vector<ll> &ans) {
    
            for(auto adjNode: adjList[node]) {
                if(adjNode != parent) {
                    differenceArr[node] += dfsPrefixSum(adjNode, node, differenceArr, ans);
                }
            }
    
            return ans[node] = differenceArr[node];
        }

    public:
        Tree(ll n, vector<pair<ll, ll>> edges) {
            this->n = n;
            adjList.resize(n+1);
            
            for(auto it: edges) {
                ll u = it.first, v = it.second;
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            parentGrid.resize(n+1, vector<ll>(parentsPower, 0));
            levelArr.resize(n+1);
            
            populateParentGrid(1, 0, 0);
        }


        void calculatePathContainsNode(vector<pair<ll, ll>> paths) {
            vector<ll> differenceArr(n+1, 0);

            for(auto it: paths) {
                ll a = it.first, b = it.second;
                ll lca = getLCA(a, b);

                differenceArr[a]++;
                differenceArr[b]++;
                differenceArr[lca]--;
                differenceArr[parentGrid[lca][0]]--;
            }

            vector<ll> ans(n+1, 0);
            dfsPrefixSum(1, 0, differenceArr, ans);

            for(int i = 1; i <= n; i++) {
                cout << ans[i] << " ";
            }
        }
};

void solve() {
    ll n, m; cin >> n >> m;

    vector<pair<ll,ll>> edges;
    for(int i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    vector<pair<ll, ll>> paths;
    for(int i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        paths.push_back({a, b});
    }



    Tree *tree = new Tree(n, edges);
    tree->calculatePathContainsNode(paths);

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
