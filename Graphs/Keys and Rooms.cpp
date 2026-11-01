// 841
// Keys and Rooms
// Medium

#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int size = rooms[node].size();
            for(int i=0;i<size;i++){
                int key = rooms[node][i];
                if(!vis[key]){
                    q.push(key);
                    vis[key] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};