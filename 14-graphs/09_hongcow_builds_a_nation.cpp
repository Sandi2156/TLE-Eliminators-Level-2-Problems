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

void dfs(ll node, vvll &adjList, vector<bool> &visited, set<ll> &govtNodes, ll &nodeCount, bool &isGoveNodePreset, ll &edgeCount) {
    visited[node] = true;
    nodeCount++;
    if(govtNodes.find(node) != govtNodes.end()) isGoveNodePreset = true;


    for(auto adjNode: adjList[node]) {
        edgeCount++;
        if(!visited[adjNode]) dfs(adjNode, adjList, visited, govtNodes, nodeCount, isGoveNodePreset, edgeCount);
    }
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vll govNodes(k);
    for(int i = 0; i < k; i++) cin >> govNodes[i];

    set<ll> govtNodeSet;
    for(auto it: govNodes) govtNodeSet.insert(it);

    vvll adjList(n + 1);
    for(int i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }


    vector<bool> visited(n + 1, false);
    vll nodeCountSetWithGovtNodes, nodeCountSetWithoutGovtNodes;

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;

        bool isGovtNodePresent = false;
        ll nodeCount = 0, edgeCount = 0;
        dfs(i, adjList, visited, govtNodeSet, nodeCount, isGovtNodePresent, edgeCount);

        ans += ((nodeCount * (nodeCount - 1)) - edgeCount) / 2;

        if(isGovtNodePresent) nodeCountSetWithGovtNodes.push_back(nodeCount);
        else nodeCountSetWithoutGovtNodes.push_back(nodeCount);
    }


    ll prev = 0;
    if(nodeCountSetWithoutGovtNodes.size() > 0) {
        prev = nodeCountSetWithoutGovtNodes[0];
        for(int i = 1; i < nodeCountSetWithoutGovtNodes.size(); i++) {
            ans += (prev * nodeCountSetWithoutGovtNodes[i]);
            prev += nodeCountSetWithoutGovtNodes[i];
        }
    }


    sort(nodeCountSetWithGovtNodes.rbegin(), nodeCountSetWithGovtNodes.rend());
    if(nodeCountSetWithGovtNodes.size() > 0) {
        ans += (prev * nodeCountSetWithGovtNodes[0]);
    }

    cout << ans << ln;

   //TC: O(n + e + log(p))
   //SC: O(n + n + e)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}