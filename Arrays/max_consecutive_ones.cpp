// Leetcode 485
// Max consecutive ones
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            if(nums[j]==1){
                ans = max(ans,j-i+1);
            }
            if(nums[j]==0){
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};