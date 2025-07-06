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
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n, 1);
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

            ll parU = getParent(u), parV = getParent(v);
            if(size[parU] > size[parV]) {
                size[parU] += size[parV];
                parent[parV] = parU;
            } else {
                size[parV] += size[parU];
                parent[parU] = parV;
            }
        }
};

void solve() {
   ll t = 1;
//    cin>>t;
   while(true) {
        ll m, n;
        cin >> m >> n;

        if(n == 0 && m == 0) break;
        
        vector<pair<ll, pair<ll, ll>>> edges;
        for(int i = 1; i <= n; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }

        sort(edges.begin(), edges.end());
        ll costSaved = 0;
        DisjointSet dsu(m);
        for(auto it: edges) {
            ll wt = it.first, u = it.second.first, v = it.second.second;
            if(dsu.isInSameComponent(u, v)) {
                costSaved += wt;
                continue;
            }

            dsu.merge(u, v);
        }

        cout << costSaved << ln;
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