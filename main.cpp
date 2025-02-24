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

void merge(int i, int mid, int j, vector<int> &arr) {
    vector<int> tmp(j-i+1);
    int k = i, l = mid+1, p = 0;

    while(k <= mid && l <= j) {
        if(arr[k] <= arr[l]) {
            tmp[p] = arr[k];
            k++;
        } else {
            tmp[p] = arr[l];
            l++;
        }
        p++;
    }

    while(k <= mid) {
        tmp[p] = arr[k];
        k++;
        p++;
    }

    while(l <= j) {
        tmp[p] = arr[l];
        l++;
        p++;
    }

    for(int t = i; t <= j; t++) {
        arr[t] = tmp[t-i];
    }
}

void mergeSort(int i, int j, vector<int> &arr) {
    if(i >= j) return;

    int mid = (i + j) / 2;
    mergeSort(i, mid, arr);
    mergeSort(mid+1, j, arr);

    merge(i, mid, j, arr);
}

void quickSort(int i, int j, vector<int> &arr) {
    if(i >= j) return;

    int pivotIdx = j;
    int left = i;
    while(left < pivotIdx) {
        if(arr[left] > arr[pivotIdx]) {
            swap(arr[left], arr[pivotIdx-1]);
            swap(arr[pivotIdx-1], arr[pivotIdx]);
            pivotIdx--;
        } else left++;
    }

    quickSort(i, pivotIdx-1, arr);
    quickSort(pivotIdx+1, j, arr);
}

void solve() {
   ll t = 1;
//    cin>>t;
   while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);
        for(auto &it: arr) cin>>it;

        quickSort(0, n-1, arr);
        for(auto it: arr) cout<<it<<" ";
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