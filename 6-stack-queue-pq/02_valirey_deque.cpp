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


void solve() {
   ll t = 1;
//    cin>>t;
   while(t--) {
        ll n, q;
        cin>>n>>q;

        vector<ll> arr(n);
        for(auto &it: arr) cin>>it;

        ll maxi = INT_MIN;
        deque<ll> dq;

        for(auto it: arr) {
            maxi = max(maxi, it);
            dq.push_back(it);
        }

        map<int, pair<ll,ll>> mp;
        int opNo = 1;
        while(dq.front() != maxi) {
            ll a = dq.front(); dq.pop_front();
            ll b = dq.front(); dq.pop_front();

            mp[opNo++] = {a, b};

            if(a > b) {
                dq.push_front(a);
                dq.push_back(b);
            } else {
                dq.push_front(b);
                dq.push_back(a);
            }
        }

        vector<ll> modifiedArr(n);
        int i = 0;
        while(!dq.empty()) {
            modifiedArr[i] = dq.front();
            dq.pop_front();
            i++;
        }

        while(q--) {
            ll p;
            cin>>p;

            if(p <= mp.size()) {
                cout<<mp[p].first<<" "<<mp[p].second<<ln;
            } else {
                p -= mp.size();
                p %= (n-1);
                cout<<modifiedArr[0]<<" "<<(p == 0 ? modifiedArr[n-1] : modifiedArr[p])<<ln;
            }
        }
   }
   //TC: O(n logn)
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