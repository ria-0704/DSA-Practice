// Leetcode 34
// First and Last Position of element in an sorted array
// Difficulty: Medium

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high = mid-1;
        }
        low = 0;
        high = n-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                last = mid;
                low = mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high = mid-1;
        }
        return {first,last};
    }
};