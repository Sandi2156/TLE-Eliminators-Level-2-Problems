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


void func(int n, vector<int> &arr, int q, vector<vector<int>> &queries) {
    vector<ll> difference_array(n+1, 0);
    for(auto &it: queries) {
        difference_array[it[0]-1]++;
        difference_array[it[1]]--;
    }

    for(int i = 0; i < n; i++)
        if(i > 0) difference_array[i] += difference_array[i-1];
    
    priority_queue<vector<ll>> pq;
    for(int i = 0; i < n; i++) {
        pq.push({difference_array[i], i});
    }
    
    vector<ll> rearranged_arr(n);
    sort(arr.begin(), arr.end());
    int i = n-1;
    while(!pq.empty()) {
        vector<ll> rec = pq.top();
        pq.pop();
        rearranged_arr[rec[1]] = arr[i];
        i--;
    }

    for(int i = 0; i < n; i++) 
        if(i > 0) rearranged_arr[i] += rearranged_arr[i-1];

    long long ans = 0;
    for(int i = 0; i < q; i++) {
        int a = queries[i][0]-1, b = queries[i][1]-1;
        ans += (rearranged_arr[b] - (a > 0 ? rearranged_arr[a-1]: 0));
    }

    cout<<ans<<endl;

}

void solve() {
    int n, q;
    cin>>n>>q;

    vector<int> arr(n);
    for(auto &it: arr) cin>>it;

    vector<vector<int>> queries(q, vector<int>(2));
    for(int i = 0; i < q; i++)
        cin>>queries[i][0]>>queries[i][1];

    func(n, arr, q, queries);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}