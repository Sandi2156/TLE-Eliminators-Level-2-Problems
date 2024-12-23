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

void divide(ll val, priority_queue<ll> &pq) {
    if(val == 1) {
        pq.push(val);
        return;
    }

    if((val & (val-1)) == 0) {
        pq.push(val/2);
        pq.push(val/2);
        return;
    }

    int i = 0;
    while((1LL << i) < val) {
        i++;
    }
    i--;
    pq.push(1LL << i);
    ll rest = val - (1LL<<i);
    if(rest & (rest-1))
        divide(rest, pq);
    else
        pq.push(rest);
}

void solve() {
    ll n, k;
    cin>>n>>k;

    if(k > n) {
        cout<<"NO"<<endl;
        return;
    }

    priority_queue<ll> pq;
    pq.push(n);

    while(pq.size() < k) {
        ll val = pq.top();
        pq.pop();

        divide(val, pq);
    }

    

    if(pq.size() == k && (k == 1 ? (n & (n-1))==0 : true)) {
        cout<<"YES"<<endl;
        while(!pq.empty()) {
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
    } else{
        cout<<"NO"<<endl;
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