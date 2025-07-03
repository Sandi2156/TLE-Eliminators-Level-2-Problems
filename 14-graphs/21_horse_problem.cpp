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
        ll n;
        vector<vector<pair<ll, ll>>> adjList;
        set<ll> nodesWithHorse;

    public:
        Dijkstra(ll n, vector<vector<pair<ll, ll>>> adjList, set<ll> nodesWithHorse) {
            this->n = n;
            this->adjList = adjList;
            this->nodesWithHorse = nodesWithHorse;
        }

        vector<pair<ll,ll>> getShortestDistance(ll u) {
            vector<pair<ll, ll>> distance(n + 1, {1e18, 1e18});
            distance[u].first = 0;
            distance[u].second = 0;

            // dist to reach node, node, isReachByHorse
            priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> que;
            ll isHorsePresentAtU = nodesWithHorse.find(u) != nodesWithHorse.end();
            que.push({ 0, {u, isHorsePresentAtU} });


            while(!que.empty()) {
                auto node = que.top();
                que.pop();

                ll distToReach = node.first, u = node.second.first, isReachedByHorse = node.second.second;
                if((isReachedByHorse ? distance[u].second : distance[u].first) < distToReach) continue;

                isReachedByHorse = isReachedByHorse || (nodesWithHorse.find(u) != nodesWithHorse.end());

                for(auto adjNode: adjList[u]) {
                    ll v = adjNode.first, distToV = isReachedByHorse ? adjNode.second / 2 : adjNode.second;
                    if(distToReach + distToV < ( isReachedByHorse ? distance[v].second : distance[v].first)) {
                        if(isReachedByHorse) distance[v].second = distToReach + distToV;
                        else distance[v].first = distToReach + distToV;

                        que.push({ isReachedByHorse ? distance[v].second : distance[v].first, { v, isReachedByHorse } });
                    }
                }
            }

            return distance;
        }
};

void solve() {
   ll t = 1;
   cin>>t;
   while(t--) {
        ll n, m, h;
        cin >> n >> m >> h;

        set<ll> nodesWithHorse;
        for(int i = 1; i <= h; i++) {
            ll node; cin >> node;
            nodesWithHorse.insert(node);
        }

        vector<vector<pair<ll, ll>>> adjList(n + 1);
        for(int i = 1; i <= m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }


        Dijkstra djk(n, adjList, nodesWithHorse);
        vector<pair<ll, ll>> distanceFromA = djk.getShortestDistance(1), distanceFromB = djk.getShortestDistance(n);

        ll ans = 1e18;
        for(int i = 1; i <= n; i++) {
            ll a = min(distanceFromA[i].first, distanceFromA[i].second);
            ll b = min(distanceFromB[i].first, distanceFromB[i].second);

            ans = min(ans, max(a, b));
        }

        if(ans >= 1e18) {
            cout << -1 << ln;
        } else cout << ans << ln;
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