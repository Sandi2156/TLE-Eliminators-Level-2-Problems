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


void solve() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63};

    // for(int i = 0; i < arr.size(); i++) {
    //     for(int j = 1; j < arr.size(); j++) {
    //         if((arr[i] & arr[j]) == 63) cout<<arr[i]<<" "<<arr[j]<<" "<<(arr[i]&arr[j])<<endl;
    //     }
    // }

    map<char, int> mp;
    mp['0'] = 0;
    mp['A'] = 10;
    mp['a'] = 36;
    mp['-'] = 62;
    mp['_'] = 63;

    string str;
    cin>>str;

    ll ans = 1, mod = 1e9+7;
    for(int i = 0; i < str.length(); i++) {
        ll num = -1;
        if(str[i] == '-' || str[i] == '_') {
            num = mp[str[i]];
        }
        else if(str[i] >= '0' && str[i] <= '9') {
            num = str[i] - '0';
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            num = mp['a'] + (str[i] - 'a');
        }
        else num = mp['A'] + (str[i] - 'A');

        ll cnt = 0;
        for(int j = 0; j < arr.size(); j++) {
            for(int k = 0; k < arr.size(); k++) {
                if((arr[j] & arr[k]) == num) cnt++;
            }
        }
        // cnt++;
        ans = (ans * cnt) % mod;
    }
    cout<<ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}