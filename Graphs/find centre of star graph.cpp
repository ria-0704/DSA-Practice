// 1791
// Find Centre Of Star Graph
// Easy

#include<vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n+1);
        for(int i=1;i<=n;i++){
            vis[i] = adj[i].size();
        }
        int m = 1;
        for(int i=1;i<=n;i++){
            if(vis[i]>vis[m]) m = i;
        }
        return m;
    }
};