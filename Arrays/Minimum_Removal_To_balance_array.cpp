// Leetcode 3634
// Minimum Removal to balance array
// Difficulty: Medium

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j = 0;
        int longest = 0;
        for(int i=0;i<n;i++){
            while(j<n && nums[j] <= (long long)nums[i]*k){
                j++;
            }
            longest = max(longest,j-i);
        }
        return n-longest;
    }
};