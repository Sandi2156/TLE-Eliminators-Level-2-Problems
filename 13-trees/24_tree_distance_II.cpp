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


class Tree {
    private:
        ll n;
        vvll adjList;
        vll sizeArr;
        vll distanceArr;
    
        void populateSizeDistance(ll node, ll parent, ll dist) {
            sizeArr[node] = 1;
            distanceArr[node] = dist;

            for(auto adjNode: adjList[node]) {
                if(adjNode != parent) {
                    populateSizeDistance(adjNode, node, 1 + dist);
                }
            }

            for(auto adjNode: adjList[node]) {
                if(adjNode != parent) {
                    sizeArr[node] += sizeArr[adjNode];
                }
            }
        }

        void dfs(ll node, ll parent, vector<ll> &dp) {
            
            if(node != 1) {
                dp[node] = dp[parent] + (n - sizeArr[node]) - sizeArr[node];
            }

            for(auto adjNode: adjList[node]) {
                if(adjNode != parent)
                    dfs(adjNode, node, dp);
            }
        }
    public:
        Tree(ll n, vvll adjList) {
            this->n = n;
            this->adjList = adjList;

            sizeArr.resize(n + 1, 0);
            distanceArr.resize(n + 1, 0);
            populateSizeDistance(1, 0, 0);
        }

        void printSumDistance() {
            ll sum = 0;
            for(auto it: distanceArr) sum += it;
            vll dp(n + 1);
            dp[1] = sum;

            dfs(1, 0, dp);

            for(int i = 1; i <= n; i++) cout << dp[i] << " ";
        }
};

void solve() {
    ll n; cin >> n;

    vvll adjList(n+1);
    for(int i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    Tree tree(n, adjList);
    tree.printSumDistance();
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