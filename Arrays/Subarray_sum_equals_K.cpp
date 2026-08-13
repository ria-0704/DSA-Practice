// Leetcode 560
// Subarray Sum Equals k
// Difficulty: Medium


#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> curSum(n);
        curSum[0] = nums[0];
        for(int i=1;i<n;i++){
            curSum[i] = curSum[i-1] + nums[i];
        }
        int c;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            c = curSum[i];
            ans += mp[c-k];
            mp[c]++;
        }
        return ans;
    }
};