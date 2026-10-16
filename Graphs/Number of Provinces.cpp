// 547
// Number of Provinces
// Medium

#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int i,vector<vector<int>> &adjL,vector<int> &vis){
        vis[i] = 1;
        for(auto it:adjL[i]){
            if(!vis[it]){
                dfs(it,adjL,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjL(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count ++;
                dfs(i,adjL,vis);
            }
        }
        return count;
    }
};