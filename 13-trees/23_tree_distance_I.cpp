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

void getDistance(ll node, ll parent, vvll &adjList, vector<ll> &distance, ll dist) {
    distance[node] = dist;

    for(auto adjNode: adjList[node]) {
        if(adjNode != parent) {
            getDistance(adjNode, node, adjList, distance, 1 + dist);
        }
    }
}

void solve() {
   ll n; cin >> n;

   vector<vector<ll>> adjList(n + 1);
   for(int i = 1; i < n; i++) {
    ll a, b; cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
   }

   vector<ll> distance(n + 1, 0);
   getDistance(1, 0, adjList, distance, 0);

   ll p, dist = INT_MIN;
   for(int i = 1; i <= n; i++) {
    if(distance[i] > dist) {
        dist = distance[i];
        p = i;
    }
   }

   distance.resize(n + 1, 0);
   getDistance(p, 0, adjList, distance, 0);
   ll q;
   dist = INT_MIN;
   for(int i = 1; i <= n; i++) {
    if(distance[i] > dist) {
        dist = distance[i];
        q = i;
    }
   }

   vector<ll> distanceFromP(n + 1, 0), distanceFromQ(n + 1, 0);
   getDistance(p, 0, adjList, distanceFromP, 0);
   getDistance(q, 0, adjList, distanceFromQ, 0);

   for(int i = 1; i <= n; i++) {
    cout << max(distanceFromP[i], distanceFromQ[i]) << " ";
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