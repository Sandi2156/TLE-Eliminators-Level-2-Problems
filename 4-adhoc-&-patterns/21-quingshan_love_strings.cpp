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

void makeGoodString(ll n, string s) {
    ll cntZero = 0, cntOne = 0;
    for(auto it: s) 
        if(it == '0') cntZero++;
        else cntOne++;
    
    if(cntOne != cntZero) {
        cout<<-1<<ln;
        return;
    }

    ll i = 0, j = n-1;
    ll noOfInsert = 0;
    vector<ll> pos;

    while(i < j) {
        if(s[i] == s[j]) {
            noOfInsert++;
            if(s[i] == '0') {
                pos.push_back(j+1);
                s.insert(j+1, "01");
                j+=2;
            } else {
                pos.push_back(i);
                s.insert(i, "01");
                j+=2;
            }
        }
        i++,j--;
    }
    cout<<noOfInsert<<ln;
    for(auto it: pos) cout<<it<<" ";
    cout<<ln;
}

void solve() {
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        string s;
        cin>>s;

        makeGoodString(n, s);
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