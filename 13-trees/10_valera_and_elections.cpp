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

void dfsSubtreeBadRoad(ll node, ll parent, vector<map<ll, ll>> &adjList, vector<bool> &subtreeContaisBadRoad) {

    for(auto adjNode: adjList[node]) {
        if(adjNode.first != parent) {
            if(adjNode.second == 2) subtreeContaisBadRoad[node] = true;
            dfsSubtreeBadRoad(adjNode.first, node, adjList, subtreeContaisBadRoad);
            if(subtreeContaisBadRoad[adjNode.first]) subtreeContaisBadRoad[node] = true;
        }
    }
}

void getCandidates(ll node, ll parent, vector<map<ll,ll>> &adjList, vector<bool> &subtreeContaisBadRoad, vector<ll> &candidates) {
    if(subtreeContaisBadRoad[node] == false) {
        if(parent == -1) return;
        if(adjList[node][parent] == 2) {
            candidates.push_back(node);
        }
        return;
    }

    for(auto adjNode: adjList[node]) {
        if(adjNode.first != parent) {
            getCandidates(adjNode.first, node, adjList, subtreeContaisBadRoad, candidates);
        }
    }
}

void solve() {
   ll n; cin >> n;
   vector<map<ll, ll>> adjList(n);

   for(int i = 1; i < n; i++) {
    ll x, y, t; cin >> x >> y >> t;
    x--,y--;

    adjList[x].insert({y, t});
    adjList[y].insert({x, t});
   }

   vector<bool> subtreeContaisBadRoad(n, false);
   dfsSubtreeBadRoad(0, -1, adjList, subtreeContaisBadRoad);

   vector<ll> candidates;
   getCandidates(0, -1, adjList, subtreeContaisBadRoad, candidates);

   cout << candidates.size() << ln;
   for(auto it: candidates) cout << it + 1 << " ";


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