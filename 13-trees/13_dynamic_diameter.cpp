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


void dfsDistance(ll node, ll parent, vector<vector<ll>> &adjList, vector<ll> &distance) {

    for(auto adjNode: adjList[node]) {
        if(adjNode != parent) {
            distance[adjNode] = 1 + distance[node];
            dfsDistance(adjNode, node, adjList, distance);
        }
    }
}

pair<ll, set<int>> getDiameter(ll n, vector<vector<ll>> &adjList) {
    vector<ll> distance(n, 0);
    dfsDistance(0, -1, adjList, distance);

    int deepestNode = -1;
    ll maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(distance[i] > maxi) {
            maxi = distance[i];
            deepestNode = i;
        }
    }

    set<int> deepestNodes;
    for(int i = 0; i < n; i++) {
        if(distance[i] == maxi) deepestNodes.insert(i);
        distance[i] = 0;
    }

    dfsDistance(deepestNode, -1, adjList, distance);
    maxi = INT_MIN;
    for(auto it: distance) {
        maxi = max(maxi, it);
    }

    for(int i = 0; i < n; i++) {
        if(distance[i] == maxi) deepestNodes.insert(i);
    }

    return {maxi, deepestNodes};
}

void solve() {

    ll n; cin >> n;

    vector<vector<ll>> adjList(n);
    for(int i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        u--,v--;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    pair<ll, set<int>> ret = getDiameter(n, adjList);

    for(int i = 0; i < n; i++) {
        if(ret.second.find(i) != ret.second.end()) {
            cout << ret.first + 1 << ln;
        } else cout << ret.first << ln;
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