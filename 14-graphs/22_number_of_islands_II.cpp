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
        int n;
        vector<int> parent;
        vector<int> size;

    public:
        DisjointSet(int n) {
            this->n = n;
            parent.assign(n, 0);
            iota(parent.begin(), parent.end(), 0);
            size.assign(n, 0);
        }

        int getParent(int u) {
            if(u == parent[u]) return u;
            return parent[u] = getParent(parent[u]);
        }

        void merge(int u, int v) {
            int parU = getParent(u), parV = getParent(v);

            if(parU == parV) return;

            if(size[parU] > size[parV]) {
                size[parU] += size[parV];
                parent[parV] = parU;
            } else {
                size[parV] += parU;
                parent[parU] = parV;
            }
        } 
};

void solve() {
   ll t = 1;
   while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        vector<vector<ll>> points;
        for(int i = 1; i <= k; i++) {
            ll u, v;
            cin >> u >> v;
            points.push_back({u, v});
        }

        DisjointSet dsu(n * m);

        ll noOfComponents = 0;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        set<pair<ll, ll>> pointsSet;

        for(auto it: points) {
            ll val = (it[0] * m) + it[1];

            noOfComponents++;

            for(int i = 0; i < 4; i++) {
                int nI = it[0] + dx[i], nJ = it[1] + dy[i];
                if(nI >= 0 && nI < n && nJ >= 0 && nJ < m && pointsSet.find({nI, nJ}) != pointsSet.end()) {
                    ll childVal = (nI * m) + nJ;
                    if(dsu.getParent(val) != dsu.getParent(childVal)) {
                        noOfComponents--;
                        dsu.merge(val, childVal);
                    }
                }
            }
             
            pointsSet.insert({it[0], it[1]});
            cout << noOfComponents << " ";
        }


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