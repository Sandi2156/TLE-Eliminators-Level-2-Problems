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
    ll t;
    cin>>t;

    while(t--) {
        ll p, q;
        cin>>p>>q;

        vector<int> primes;
        ll nq = q;
        for(int i = 2; i * i <= nq; i++) {
            if(nq % i == 0) {
                primes.push_back(i);
                while(nq % i == 0) nq /= i;
            }
        }
        if(nq > 1) primes.push_back(nq);

        ll ans = p;
        for(auto prime: primes) {
            ll expop = 0, expoq = 0;
            ll np = p, nq = q;
            while(np % prime == 0) {
                expop++;
                np /= prime;
            }
            while(nq % prime == 0) {
                expoq++;
                nq /= prime;
            }

            ll drop = expop - expoq + 1;
            ll val = 1;
            for(int i = 0; i < drop; i++) {
                val *= prime;
            }
            ans = min(ans, val);
        }
        // cout<<ans<<ln;
        cout<<p/ans<<ln;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}