// Leetcode 645
// Set Mismatch
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        int missing = -1,duplicate = -1;
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(hash[i]==2){
                duplicate = i;
            }
        }
        for(int i=1;i<=n;i++){
            if(hash[i]==0){
                missing = i;
            }
        }
        v.push_back(duplicate);
        v.push_back(missing);
        return v;
    }
};