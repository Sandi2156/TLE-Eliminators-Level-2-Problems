#include <bits/stdc++.h>
using namespace std;

void func(int n, vector<long> stones, int m, vector<vector<int>> &queries) {
    vector<long long> prefixOne(n);
    for(int i = 0; i < n; i++) {
        prefixOne[i] = stones[i];
        if(i > 0) prefixOne[i] += prefixOne[i-1];
    }

    sort(stones.begin(), stones.end());
    vector<long long> prefixTwo(n);
    for(int i = 0; i < n; i++) {
        prefixTwo[i] = stones[i];
        if(i > 0) prefixTwo[i] += prefixTwo[i-1];
    }

    vector<long long> res;
    for(auto &it: queries) {
        int type = it[0], l = it[1]-1, r = it[2]-1;
        if(type == 1) {
            res.push_back(prefixOne[r] - (l > 0 ? prefixOne[l-1] : 0));
        } else {
            res.push_back(prefixTwo[r] - (l > 0 ? prefixTwo[l-1] : 0));
        }
    }

    for(auto it: res) cout<<it<<endl;
}

int main() {
    int n;
    cin>>n;
    vector<long> stones(n);
    for(auto &stone: stones) cin>>stone;

    int m;
    cin>>m;
    vector<vector<int>> queries(m, vector<int>(3));
    for(int i = 0; i < m; i++) {
        cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
    }

    func(n, stones, m, queries);

    return 0;
}