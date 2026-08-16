// Leetcode 152
// Maximum Product Subarrays
// Difficulty: Hard


#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = nums[0];
        int curMax,curMin;
        for(int i=1;i<n;i++){
            curMax = max(nums[i],max(nums[i]*prevMax,nums[i]*prevMin));
            curMin = min(nums[i],min(nums[i]*prevMax,nums[i]*prevMin));
            ans = max(ans,curMax);
            prevMax = curMax;
            prevMin = curMin;
        }
        return ans;
    }
};