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
   cin>>t;
   while(t--) {
        string s;
        cin>>s;

        ll ans = 0;
        
        int i = 0;
        while(i < s.length()) {
            if(s[i] == '0') {
                i++;
            } else {
                int j = i;
                while(j < s.length() && s[j] == '1') j++;
                ll cnt = j-i;

                ll a = cnt/2;
                ll b = (cnt+1) - a;
                ans = max(ans, a*b);
                ans = max(ans, (a+1)*(b-1));
                i = j;
            }
        }

        ll cnt = 0;
        i = 0;
        int j = s.length()-1;
        while(i < s.length() && s[i] == '1') i++,cnt++;
        while(j > i && s[j] == '1')  j--, cnt++;
        ll a = cnt/2;
        ll b = (cnt+1) - a;
        ans = max(ans, a*b);
        ans = max(ans, (a+1)*(b-1));

        if(cnt == s.length()) ans = cnt * cnt;

        cout<<ans<<ln;
   }
   //TC: O(n)
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