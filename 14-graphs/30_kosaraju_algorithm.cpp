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

pair<vector<vector<ll>>, vector<vector<ll>>> kosaraju2(vector<vector<ll>> &adj) {
    /*
        1. Sort the vertices based on finishing time
        2. transpose the graph
        3. run dfs and get the components
        4. get the condensed graph
    */

    vector<vector<ll>> components, adj_cond;
    ll n = adj.size();

    // 1. get the verticies decreasing of their finish time
    vector<int> visited(n, 0);
    vector<ll> order;
    auto dfs = [&](auto &&dfs, ll node) -> void {
        visited[node] = 1;
        for(auto adjNode: adj[node]) {
            if(!visited[adjNode]) dfs(dfs, adjNode);
        }

        order.push_back(node);
    };

    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs(dfs, i);
    }
    reverse(order.begin(), order.end());
    fill(visited.begin(), visited.end(), 0);

    // 2. transpose of the graph
    vector<vector<ll>> adj_rev(n+1);
    for(ll i = 0; i < n; i++) {
        for(auto v: adj[i])
            adj_rev[v].push_back(i);
    }

    // 3. dfs rev
    auto dfs_rev = [&](auto &&dfs_rev, ll node, vector<ll> &comp) -> void {
        visited[node] = 1;
        comp.push_back(node);

        for(auto adjNode: adj_rev[node]) {
            if(!visited[adjNode]) dfs_rev(dfs_rev, adjNode, comp);
        }
    };

    vector<ll> roots(n+1);
    for(auto i: order) {
        if(!visited[i]) {
            vector<ll> comp;
            dfs_rev(dfs_rev, i, comp);
            components.push_back(comp);

            ll root = *min_element(comp.begin(), comp.end());
            for(auto it: comp) roots[it] = root;
        }
    }


    // 4. get the condensed graph
    adj_cond.resize(n+1);
    for(ll u = 0; u < n; u++) {
        for(ll v: adj[u]) {
            if(roots[u] != roots[v]) adj_cond[roots[u]].push_back(roots[v]);
        }
    }


    return {components, adj_cond};
}

void solve() {


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