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

bool canIncreaseMex(ll n, vector<ll> &arr) {
    unordered_map<ll, ll> mp;
    for(auto it: arr) mp[it]++;

    ll cur_mex;
    for(ll i = 0; i < n+1; i++) {
        if(mp.find(i) == mp.end()) {
            cur_mex = i;
            break;
        }
    }

    if(mp.find(cur_mex + 1) == mp.end()) {
        for(auto it: mp) {
            if(it.second > 1) return true;
            if(it.first > cur_mex + 1) return true;
        }
        return false;
    }

    ll l, m;
    for(l = 0; l < n; l++)
        if(arr[l] == cur_mex + 1) break;
    for(m = n - 1; m >= 0; m--)
        if(arr[m] == cur_mex + 1) break;
    
    while(l <= m) {
        if(arr[l] != cur_mex + 1) {
            mp[arr[l]]--;

            if(arr[l] < cur_mex && mp[arr[l]] == 0) return false;
        }
        l++;
    }
    return true;
}

void solve() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        vector<ll> arr(n);
        for(auto &it: arr) cin>>it;

        if (canIncreaseMex(n, arr))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}