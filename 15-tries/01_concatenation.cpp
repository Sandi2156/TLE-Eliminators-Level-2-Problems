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


class TrieNode {
    private:
        int strings_ending_here;
        int strings_passing_below;
        TrieNode* children[26];
    public:
        TrieNode() {
            strings_ending_here = strings_passing_below = 0;
            for(int i = 0; i < 26; i++) children[i] = NULL;
        }

        bool isCharacterPresent(char ch) {
            return children[ch] != NULL;
        }

        void createNewNode(char ch) {
            children[ch - 'a'] = new TrieNode();
        }

        TrieNode* getNode(char ch) {
            return children[ch - 'a'];
        }

        void handlePassingNode() {
            strings_passing_below++;
        }

        void handleEndingNode() {
            strings_ending_here++;
        }

        int getNumberOfStringEnding() {
            return strings_ending_here;
        }

        int getNumberOfStringPassing() {
            return strings_passing_below;
        }

        void handleRemovePassingNode() {
            strings_passing_below--;
        }

        void handleRemoveEndingNode() {
            strings_ending_here--;
        }
};

class Trie {
    private:
        TrieNode *root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void add(string word) {
            TrieNode *cur = root;
            
            for(char ch: word) {
                if(!cur->isCharacterPresent(ch))
                    cur->createNewNode(ch);
                cur = cur->getNode(ch);
                cur->handlePassingNode();
            }
            cur->handleEndingNode();
        }

        bool search(string word) {
            TrieNode *cur = root;

            for(char ch: word) {
                if(!cur->isCharacterPresent(ch)) return false;
                cur = cur->getNode(ch);
            }

            return cur->getNumberOfStringEnding() > 0;
        }

        void updatePrefix(string word, vector<bool> &prefix) {
            TrieNode *cur = root;

            int i = 0;
            for(char ch: word) {
                if(!cur->isCharacterPresent(ch)) return;

                cur = cur->getNode(ch);
                prefix[i++] = true;
            }
        }
};


void solve() {
    ll n;
    cin >> n;

    vector<string> vec;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;

        vec.push_back(str);
    }

    string x;
    cin >> x;

    Trie trie1, trie2;
    for(auto str: vec) {
        trie1.add(str);
    }

    for(auto str: vec) {
        reverse(str.begin(), str.end());
        trie2.add(str);
    }

    vector<bool> prefix(n, false), suffix(n, false);
    trie1.updatePrefix(x, prefix);
    trie2.updatePrefix(x, suffix);

    bool found = false;
    for(int i = 0; i < n-1; i++) {
        if(prefix[i] && suffix[i+1]) {
            found = true;
            break;
        }
    }

    if(found) cout << "YES" << ln;
    else cout << "NO" << ln;


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