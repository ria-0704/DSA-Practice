// 1971
// Find if path Exists in Graph
// Easy


#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& adj, int source,vector<int>& vis){
        vis[source] = 1;
        for(auto it : adj[source]){
            if(!vis[it]) dfs(adj,it,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        dfs(adj,source,vis);
        return vis[destination];
    }
};