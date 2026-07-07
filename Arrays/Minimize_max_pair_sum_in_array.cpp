// Leetcode - 1877
// Minimum Maximum Pair Sum in Array
// Difficulty: Medium

#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        int ans = INT_MIN;
        while(i<j){
            ans = max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};