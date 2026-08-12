// Leetcode 31
// Next Permutation
// Difficulty: Medium


#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int a=-1,b;
        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                a=i;
                break;
            }
        }
        if(a==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[a]){
                b = i;
                break;
            }
        }
        swap(nums[a],nums[b]);
        reverse(nums.begin()+a+1,nums.end());
    }
};