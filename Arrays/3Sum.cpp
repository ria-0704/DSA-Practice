// Leetcode 15
// 3Sum
// Difficulty: Medium


#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v(3);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                    continue;
                }
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
            if(sum<0){
                l++;
            }
            else if(sum>0){
                r--;
            }
            else{
                v[0] = nums[i];
                v[1] = nums[l];
                v[2] = nums[r];
                ans.push_back(v);
                while(l<r && nums[l]==nums[l+1]){
                    l++;
                }
                while(l<r && nums[r]==nums[r-1]){
                    r--;
                }
                l++;
                r--;
            }
            }
        }    
        return ans;
    }
};