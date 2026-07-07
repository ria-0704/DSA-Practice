// Leetcode 26
// Remove duplicate from sorted arrays
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = i+1;
        int n = nums.size();
        while(j<n){
            if(nums[j]>nums[i]){
                swap(nums[i+1],nums[j]);
                i++;
            }
            j++;
        }
        return i+1;
    }
};