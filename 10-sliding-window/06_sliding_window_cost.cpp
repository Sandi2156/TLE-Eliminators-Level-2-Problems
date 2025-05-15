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
   while(t--) {
        ll n, k;
        cin >> n >> k;
        vll arr(n);
        for0(i, n) cin >> arr[i];

        multiset<ll> low, high;
        ll leftSum = 0, rightSum = 0;
        vll ans;

        auto balance = [&]() {
            if(low.size() > high.size() + 1) {
                high.insert(*low.rbegin());
                rightSum += *low.rbegin();
                leftSum -= *low.rbegin();
                low.erase(prev(low.end()));
            }

            if(high.size() > low.size()) {
                low.insert(*high.begin());
                leftSum += *high.begin();
                rightSum -= *high.begin();
                high.erase(high.begin());
            }
        };

        for(int i = 0; i < n; i++) {
            if(low.empty() || arr[i] <= *low.rbegin()) {
                leftSum += arr[i];
                low.insert(arr[i]);
            }
            else {
                rightSum += arr[i];
                high.insert(arr[i]);
            }
            balance();

            if(i >= k - 1) {
                ll median = *low.rbegin();
                ans.push_back(low.size() * median - leftSum + rightSum - high.size() * median);

                if(arr[i - k + 1] <= *low.rbegin()) {
                    low.erase(low.find(arr[i - k + 1]));
                    leftSum -= arr[i - k + 1];
                }
                else {
                    high.erase(high.find(arr[i - k + 1]));
                    rightSum -= arr[i - k + 1];
                }
                balance();
            }
        }

        for(auto val: ans) cout << val << " ";
   }
   //TC: O(nlogk)
   //SC: O(k)
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    solve();
    return 0;
}