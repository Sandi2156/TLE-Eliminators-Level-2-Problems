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
        vector<ll> parent;
        vector<ll> size;
    public:
        DisjointSet(ll n) {
            this->n = n;
            size.assign(n + 1, 1);
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
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
    ll n, m1, m2;
    cin >> n >> m1 >> m2;

    DisjointSet dsuMocha(n), dsuDiana(n);

    for(int i = 1; i <= m1; i++) {
        ll u, v;
        cin >> u >> v;
        dsuMocha.merge(u, v);
    }

    for(int i = 1; i <= m2; i++) {
        ll u, v;
        cin >> u >> v;
        dsuDiana.merge(u, v);
    }

    ll count = 0;
    vector<vector<ll>> ans;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!dsuMocha.isInSameComponent(i, j) && !dsuDiana.isInSameComponent(i, j)) {
                count++;
                ans.push_back({i, j});

                dsuMocha.merge(i, j);
                dsuDiana.merge(i, j);
            }
        }
    }

    cout << count << ln;
    for(auto it: ans) {
        cout << it[0] << " " << it[1] << ln;
    }

   //TC: O(m1 + m2 + n*n)
   //SC: O(n + n + n * n)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}