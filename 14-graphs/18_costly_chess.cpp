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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        vector<vector<ll>> bucks(8, vector<ll>(8, LLONG_MAX));
        bucks[a][b] = 0;
        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
        pq.push({0, {a, b}});

        vector<pair<int ,int>> directions = {{-2, 1}, {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            ll buckToNode = node.first, i = node.second.first, j = node.second.second;

            if(buckToNode > bucks[i][j]) continue;

            for(auto it: directions) {
                ll newI = i + it.first, newJ = j + it.second;
                ll buckCost = buckToNode + ((i * newI) + (j * newJ));

                if(newI >= 0 && newI < 8 && newJ >= 0 && newJ < 8 && buckCost < bucks[newI][newJ]) {
                    bucks[newI][newJ] = buckCost;
                    pq.push({ buckCost, {newI, newJ} });
                }
            }
        }

        if(bucks[c][d] == LLONG_MAX) cout << -1 << ln;
        else cout << bucks[c][d] << ln;
   }
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