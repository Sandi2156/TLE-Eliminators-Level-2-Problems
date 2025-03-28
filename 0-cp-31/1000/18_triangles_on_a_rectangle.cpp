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


ll getDoubleArea(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

void solve() {
   ll t = 1;
   cin>>t;
   while(t--) {
        ll w, h;
        cin>>w>>h;

        ll n1;
        cin>>n1;
        vll arr1(n1);
        for0(i, n1) cin>>arr1[i];

        ll n2; cin>>n2;
        vll arr2(n2);
        for0(i, n2) cin>>arr2[i];

        ll n3; cin>>n3;
        vll arr3(n3);
        for0(i, n3) cin>>arr3[i];

        ll n4; cin>>n4;
        vll arr4(n4);
        for0(i, n4) cin>>arr4[i];

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        sort(arr3.begin(), arr3.end());
        sort(arr4.begin(), arr4.end());

        ll ans = INT_MIN;

        for0(i, n1) {
            ans = max(ans, getDoubleArea(arr1[i], 0, arr2[0], h, arr2[n2-1], h));
            ans = max(ans, getDoubleArea(arr1[i], 0, 0, arr3[0], 0, arr3[n3-1]));
            ans = max(ans, getDoubleArea(arr1[i], 0, w, arr4[0], w, arr4[n4-1]));
        }
        for0(i, n2) {
            ans = max(ans, getDoubleArea(arr2[i], h, arr1[0], 0, arr1[n1-1], 0));
            ans = max(ans, getDoubleArea(arr2[i], h, 0, arr3[0], 0, arr3[n3-1]));
            ans = max(ans, getDoubleArea(arr2[i], h, w, arr4[0], w, arr4[n4-1]));
        }
        for0(i, n3) {
            ans = max(ans, getDoubleArea(0, arr3[i], w, arr4[0], w, arr4[n4-1]));
            ans = max(ans, getDoubleArea(0, arr3[i], arr1[0], 0, arr1[n1-1], 0));
            ans = max(ans, getDoubleArea(0, arr3[i], arr2[0], h, arr2[n2-1], h));
        }
        for0(i, n4) {
            ans = max(ans, getDoubleArea(w, arr4[i], 0, arr3[0], 0, arr3[n3-1]));
            ans = max(ans, getDoubleArea(w, arr4[i], arr1[0], 0, arr1[n1-1], 0));
            ans = max(ans, getDoubleArea(w, arr4[i], arr2[0], h, arr2[n2-1], h));
        }

        cout<<ans<<ln;
   }
   //TC: O(n1+n2+n3+n4)
   //SC: O(1)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}