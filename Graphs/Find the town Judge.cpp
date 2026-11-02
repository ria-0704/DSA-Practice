// 997
// Find the town Judge
// Easy

#include<vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdeg(n+1);
        vector<int> indeg(n+1);
        for(auto it : trust){
            outdeg[it[0]]++;
            indeg[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(outdeg[i]==0 && indeg[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};