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

void dijkstra(ll n, ll src, vector<map<ll, ll>> &adjList, vll &distArr) {
    distArr.resize(n+1, INT_MAX);
    distArr[src] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push({0, src});

    while(!pq.empty()) {
        ll node = pq.top().first, dist = pq.top().second;
        pq.pop();

        if(dist > distArr[node]) continue;

        for(auto adjNode: adjList[node]) {
            if(dist + adjNode.second < distArr[adjNode.first]) {
                distArr[adjNode.first] = dist + adjNode.second;
                pq.push({ distArr[adjNode.first], adjNode.first });
            }
        }
    }
}

void solve() {
   ll t = 1;
   cin>>t;
   while(t--) {
       ll n, m; cin >> n >> m;

       vector<map<ll, ll>> adjList(n + 1);
       for(int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adjList[u][v] = w;
        adjList[v][u] = w;
       }

       ll src, dest;
       cin >> src >> dest;

       vector<ll> shortestDistanceFromSource, shortestDistanceFromDestination;
       dijkstra(n, src, adjList, shortestDistanceFromSource);
       dijkstra(n, dest, adjList, shortestDistanceFromDestination);


       ll ans = INT_MIN;
       for(int i = 1; i <= n; i++) {
        for(auto adjNode: adjList[i]) {
            ll halfDist = adjNode.second / 2;
            ll dist1 = shortestDistanceFromSource[i] + halfDist + shortestDistanceFromDestination[adjNode.first];
            ll dist2 = shortestDistanceFromDestination[i] + halfDist + shortestDistanceFromSource[adjNode.first];

            ans = min(ans, min(dist1, dist2));
        }
       }

       cout << ans << ln;

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