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

class DisjointSet {
    private:
        ll n;
        vll parent;
        vll size;
    public:
        DisjointSet(ll n) {
            this->n = n;
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n+1, 1);
        }

        ll getParent(ll u) {
            if(u == parent[u]) return u;
            return parent[u] = getParent(parent[u]);
        }

        bool isInSameComponent(ll u, ll v) {
            return getParent(u) == getParent(v);
        }

        void merge(ll u, ll v) {
            if(isInSameComponent(u, v)) return;

            ll par_u = getParent(u), par_v = getParent(v);
            if(size[par_u] > size[par_v]) {
                size[par_u] += size[par_v];
                parent[par_v] = par_u;
            } else {
                size[par_v] += size[par_u];
                parent[par_u] = par_v;
            }
        }
};


void solve() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> cityPoints;
    for(int i = 1; i <= n; i++) {
        ll u, v;
        cin >> u >> v;
        cityPoints.push_back({u, v});
    }

    vector<ll> costToBuildPowerStation(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> costToBuildPowerStation[i];
    }

    vector<ll> K(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> K[i];
    }


    vector<pair<ll, pair<ll, ll>>> nodesWithWeights;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll cost = (abs(cityPoints[i].first - cityPoints[j].first) + abs(cityPoints[i].second - cityPoints[j].second)) * (K[i+1] + K[j+1]);
            nodesWithWeights.push_back({cost, {i+1, j+1}});
        }
    }

    for(int i = 1; i <= n; i++) {
        nodesWithWeights.push_back({costToBuildPowerStation[i], {0, i}});
    }


    sort(nodesWithWeights.begin(), nodesWithWeights.end());

    DisjointSet dsu(n);

    vector<pair<ll, ll>> mstCities;
    vll mstPowerStation;
    ll cost = 0;
    for(auto node: nodesWithWeights) {
        if(dsu.isInSameComponent(node.second.first, node.second.second)) continue;

        cost += node.first;
        if(node.second.first == 0) mstPowerStation.push_back(node.second.second);
        else mstCities.push_back({node.second.first, node.second.second});
        dsu.merge( node.second.first, node.second.second );
    }

    cout << cost << ln;
    cout << mstPowerStation.size() << ln;
    for(auto it: mstPowerStation) cout << it << " ";
    cout << ln;
    cout << mstCities.size() << ln;
    for(auto it: mstCities) cout << it.first << " " << it.second << ln;

   //TC: O(n * n + log(n*n) + n)
   //SC: O(n*n+n)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}