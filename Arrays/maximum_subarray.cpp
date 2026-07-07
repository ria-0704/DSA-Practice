// Leetcode 53
// Maximum Subarray
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int current = nums[0];
        int n = nums.size();
        for(int i=1; i<n; i++){
            current = max(current+nums[i],nums[i]);
            maxSum = max(current,maxSum);
        }
        return maxSum;
    }
};