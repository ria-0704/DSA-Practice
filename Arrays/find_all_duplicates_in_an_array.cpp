// Leetcode 442
// Find all duplicates in an array 
// Difficulty: Medium

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int index = abs(nums[i])-1;
            if(nums[index]<0){
                v.push_back(abs(nums[i]));
            }
            else{
                nums[index] = -nums[index];
            }
        }
        
        return v;
    }
};