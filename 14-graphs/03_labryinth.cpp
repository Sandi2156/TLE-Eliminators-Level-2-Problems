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

pair<int, int> getStartingPoint(vector<string> &grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') return {i, j};
        }
    }
    return {-1, -1};
}

string getDirection(int a, int b) {
    if(a == 0) {
        if(b == 1) return "R";
        return "L";
    }
    if(a == 1) return "D";
    return "U";
}

string getPath(int i, int j, vector<vector<string>> &directions, vector<string> &grid) {

    string path = "";
    while(grid[i][j] != 'A') {
        if(directions[i][j] == "R") {
            path += "R";
            j--;
        } else if(directions[i][j] == "L") {
            path += "L";
            j++;
        } else if(directions[i][j] == "D") {
            path += "D";
            i--;
        } else {
            path += "U";
            i++;
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

void solve() {
    ll n, m; cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    auto startingPoint = getStartingPoint(grid);

    queue<pair<int, int>> que;
    que.push({startingPoint.first, startingPoint.second});
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[startingPoint.first][startingPoint.second] = true;

    vector<vector<string>> directions(n, vector<string>(m));

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    bool found = false;
    int destI, destJ;

    while(!que.empty()) {
        auto node = que.front();
        que.pop();

        int i = node.first, j = node.second;
        if(grid[i][j] == 'B') {
            found = true;
            destI = i;
            destJ = j;
            break;
        }

        for(int p = 0; p < 4; p++) {
            int nx = i + dx[p], ny = j + dy[p];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && (grid[nx][ny] == '.' || grid[nx][ny] == 'B')) {
                visited[nx][ny] = true;
                que.push({nx, ny});

                directions[nx][ny] = getDirection(dx[p], dy[p]);
            }
        }
    }

    if(!found) {
        cout << "NO" << ln;
    } else {
        cout << "YES" << ln;
        // cout << destI << destJ<< ln;
        string path = getPath(destI, destJ, directions, grid);
        cout << path.size() << ln;
        cout << path << ln;
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