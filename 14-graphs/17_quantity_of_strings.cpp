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

ll MOD = 1e9 + 7;


class DisjointSet {
    private:
        ll n;
        vector<ll> parent, size;

    public:
        DisjointSet(ll n) {
            this->n = n;
            parent.assign(n, 0);
            size.assign(n, 0);
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
            if(getParent(u) != getParent(v)) {
                ll parU = getParent(u), parV = getParent(v);

                if(size[parU] > size[parV]) {
                    parent[parV] = parU;
                    size[parU] += size[parV];
                } else {
                    parent[parU] = parV;
                    size[parV] += size[parU];
                }
            }
        }

        ll getNoOfComponents() {
            ll count = 0;
            for(int i = 0; i < n; i++) {
                if(i == getParent(i)) count++;
            }

            return count;
        }
};

ll power(ll a, ll b) {
    if(b == 0) return 1;

    ll ans = power(a, b/2);
    ans *= ans;

    ans %= MOD;
    if(b & 1) ans *= a;
    ans %= MOD;

    return ans;
}

void solve() {

    ll n, m, k;
    cin >> n >> m >> k;

    DisjointSet dsu(n);
    for(int i = 0; i + k - 1 < n; i++) {
        ll p = i, q = i + k - 1;
        while(p <= q) {
            dsu.merge(p, q);
            p++,q--;
        }
    } 

    ll componentsCount = dsu.getNoOfComponents();
    cout << power(m, componentsCount) << ln;

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