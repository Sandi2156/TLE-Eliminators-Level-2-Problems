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

class MaxHeap {
    private:
        vector<int> heap;
        int size;
    public:
        MaxHeap(vector<int> arr) {
            this->heap = arr;
            this->size = arr.size();
            build();
        }

        void HeapifyUp(int i) {
            while(i > 0) {
                int p = (i - 1) / 2;
                if(heap[p] <= heap[i]) {
                    swap(heap[p], heap[i]);
                    i = p;
                } else break;
            }
        }

        void HeapifyDown(int i) {
            while(2*i+1 < size) {
                int cl = 2*i+1, cr = 2*i+2;
                int vl = cl >= size ? INT_MIN : heap[cl];
                int vr = cr >= size ? INT_MIN : heap[cr];
                int mi = vl >= vr ? cl: cr, mv = max(vl, vr);

                if(heap[i] < mv) {
                    swap(heap[i], heap[mi]);
                    i = mi;
                } else break;
            }
        }

        void build() {
            // Build Heap
            /*
                Max Heap
                Algo -> Start with the last non-leaft node and traverse to 1
                    and perform HeapifyDown in every node
                Index of last non-leaft node -> n/2 - 1 ( as this is complete binary tree.
                    index would be parent of last node. )
                
                TO: O(n logn)
            */
            for(int node = this->size/2-1; node >= 0; node--) {
                this->HeapifyUp(node);
            }
        }

        int peek() {
            // Peek
            /*
                first element of the list is the max element
            */
           if(this->size == 0) {
            cout<<"Heap is empty"<<endl;
            return;
           }
           return this->heap[0];
        }

        void insert(int val) {
            // Insert
            /*
                Algo: 
                    1. Insert at the end of list
                    2. Heapify-Up the value
            */
           this->heap.push_back(val);
           this->size++;

           this->HeapifyUp(this->size-1);
        }

        void pop() {
            // Delete
            /*
                Algo:
                    1. swap with last element
                    2. Delete from back
                    3. Heapify-Down the root
            */
            if(this->size == 0) {
                cout<<"Heap is empty"<<endl;
                return;
           }
           swap(this->heap[0], this->heap[this->size]);
           this->heap.pop_back();
           this->size--;

           this->HeapifyDown(0);
        }
 };

void solve() {
   ll t = 1;
   cin>>t;
   while(t--) {
       
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