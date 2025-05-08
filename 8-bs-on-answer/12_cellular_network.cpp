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

bool predicate(ll x, vll &a, vll &b, ll n, ll m) {
    vector<pair<ll, ll>> rangeArr(m);
    for(int i = 0; i < m; i++) {
        rangeArr[i] = make_pair(b[i]-x, b[i]+x);
    }

    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] >= rangeArr[j].first && a[i] <= rangeArr[j].second) {
            i++;
        } else if(a[i] > rangeArr[j].second) j++;
        else return false;
    }

    return i == n;
}

void solve() {
   ll t = 1;
   // cin>>t;
   while(t--) {
        ll n, m;
        cin>>n>>m;

        vll a(n), b(m);
        for0(i, n) cin>>a[i];
        for0(i, m) cin>>b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll low = 0, high = 2000000002, ans = -1;
        while(low <= high) {
            ll mid = (low + high) / 2;

            if(predicate(mid, a, b, n, m)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        cout<<ans<<ln;
   }
   //TC: O(30*n)
   //SC: O(n)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}