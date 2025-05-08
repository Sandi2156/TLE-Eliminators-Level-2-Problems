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

long double getMaxSumWithLengthAtleastD(vector<long double> &arr, ll n, ll d) {
    vector<long double> prefixSum(n);
    for0(i, n) {
        if(i == 0) prefixSum[i] = arr[i];
        else prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    long double minSoFar = 0, ans = INT_MIN;
    for(int i = d-1; i < n; i++) {
        long double highestSumEndingAtCurrentElement = prefixSum[i] - minSoFar;
        minSoFar = min(minSoFar, prefixSum[i-d+1]);
        ans = max(ans, highestSumEndingAtCurrentElement);
    }

    return ans;
}

bool predicate(long double x, vector<long double> &arr, ll n, ll d) {
    vector<long double> modifiedArr(n);
    for0(i, n) {
        modifiedArr[i] = arr[i] - x;
    }

    return getMaxSumWithLengthAtleastD(modifiedArr, n, d) >= 0;
}


pair<int, int> findRangeWithSumGreaterThanZero(vector<long double> &arr, ll n, ll d) {
    vector<long double> prefixSum(n);
    for0(i, n) {
        if(i == 0) prefixSum[i] = arr[i];
        else prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    long double minSoFar = 0, ans = INT_MIN;
    int start_idx = 0;
    for(int i = d-1; i < n; i++) {
        long double highestSumEndingAtCurrentElement = prefixSum[i] - minSoFar;
        if(highestSumEndingAtCurrentElement >= 0) return make_pair(start_idx, i);
        // minSoFar = min(minSoFar, prefixSum[i-d+1]);
        if(prefixSum[i-d+1] < minSoFar) {
            minSoFar = prefixSum[i-d+1];
            start_idx = i-d+2;
        }
        ans = max(ans, highestSumEndingAtCurrentElement);
    }

}

pair<int, int> getRange(long double x, vector<long double> &arr, ll n, ll d) {
    vector<long double> modifiedArr(n);
    for0(i, n) {
        modifiedArr[i] = arr[i] - x;
    }

    return findRangeWithSumGreaterThanZero(modifiedArr, n, d);
}

void solve() {
   ll t = 1;
   // cin>>t;
   while(t--) {
        ll n, d;
        cin>>n>>d;

        vector<long double> arr(n);
        for0(i, n) cin>>arr[i];

        long double low = 0, high = 100, ans = -1;
        int iterations = 100;
        for(int i = 0; i < iterations; i++) {
            long double mid = (low + high) / 2;

            if(predicate(mid, arr, n, d)) {
                ans = mid;
                low = mid;
            } else high = mid;
        } 

        pair<int, int> rangeAns = getRange(ans, arr, n, d);
        cout<<rangeAns.first+1<<" "<<rangeAns.second+1<<ln;
   }
   //TC: O(100*n)
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