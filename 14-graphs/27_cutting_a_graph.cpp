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
        vll parent, size;

    public:
        DisjointSet(ll n) {
            this->n = n;
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n + 1, 1);
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

    ll n, m, k;
    cin >> n >> m >> k;

    set<pair<ll, ll>> edges;
    for(int i = 1; i <= m; i++) {
        ll u, v; cin >> u >> v;
        edges.insert({u, v});
    }

    vector<pair<string, pair<ll, ll>>> operations;
    for(int i = 1; i <= k; i++) {
        string str;
        ll u, v;
        cin >> str;
        cin >> u >> v;

        operations.push_back({str, {u, v}});

        if(edges.find({u, v}) != edges.end()) edges.erase({u, v});
        if(edges.find({v, u}) != edges.end()) edges.erase({v, u});
    }

    reverse(operations.begin(), operations.end());

    DisjointSet dsu(n);
    for(auto it: edges) {
        dsu.merge(it.first, it.second);
    }

    vector<string> ans;
    for(auto it: operations) {
        if(it.first == "cut") {
            dsu.merge(it.second.first, it.second.second);
        } else {
            if(dsu.isInSameComponent(it.second.first, it.second.second)) ans.push_back("YES");
            else ans.push_back("NO");
        }
    }

    for(auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << ln;
    }

   //TC: O(mlogm + klogm + klogn)
   //SC: O(n + m)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}