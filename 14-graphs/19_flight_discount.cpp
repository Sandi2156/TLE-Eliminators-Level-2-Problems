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

class Dijkstra {
    private:
        ll n, m;
        vector<map<ll, ll>> adjList;

    public:
        Dijkstra(ll n, ll m, vector<pair<ll, pair<ll, ll>>> edges) {
            this->n = n;
            adjList.assign(n + 1, {});
            for(auto it: edges) {
                ll u = it.first, v = it.second.first, cost = it.second.second;
                adjList[u][v] = cost;
            }
        }

        vector<ll> getMinimumCost(ll u) {
            vector<ll> cost(n + 1, LLONG_MAX);
            cost[u] = 0LL;

            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
            pq.push({0LL, u});

            while(!pq.empty()) {
                auto node = pq.top();
                pq.pop();
                ll u = node.second, costToNode = node.first;

                if(costToNode > cost[u]) continue;

                for(auto adjNode: adjList[u]) {
                    ll v = adjNode.first, costToV = adjNode.second;
                    if(costToNode + costToV < cost[v]) {
                        cost[v] = costToNode + costToV;
                        pq.push({ cost[v], v });
                    }
                }
            }

            return cost;
        }
};

void solve() {
    ll n, m; cin >> n >> m;

    vector<pair<ll, pair<ll, ll>>> edges1, edges2;
    for(int i = 1; i <= m; i++) {
        ll u, v, cost;
        cin >> u >> v >> cost;

        edges1.push_back({ u, {v, cost} });
        edges2.push_back({v, {u, cost}});
    }

    Dijkstra dj1(n, m, edges1), dj2(n, m, edges2);

    vector<ll> distanceFromSource = dj1.getMinimumCost(1);
    vector<ll> distanceFromDestination = dj2.getMinimumCost(n);
    
    ll ans = LLONG_MAX;
    for(auto it: edges1) {
        ll u = it.first, v = it.second.first, costEdge = it.second.second;

        if(distanceFromSource[u] == LLONG_MAX || distanceFromDestination[v] == LLONG_MAX) continue;

        ll totalCost = distanceFromSource[u] + (costEdge / 2) + distanceFromDestination[v];
        ans = min(totalCost, ans);
    }

    cout << ans << ln;
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