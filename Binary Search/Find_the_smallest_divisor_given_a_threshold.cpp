// Leetcode 1283
// Find the smallest divisor given a threshold
// Difficulty: Medium


#include<vector>
using namespace std;
class Solution {
public:
    bool possible(vector<int> nums, int mid, int threshold){
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%mid==0) sum+= (nums[i]/mid);
            else sum += (nums[i]/mid)+1;
        }
        if(sum>threshold) return false;
        else return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>high) high = nums[i];
        }
        int ans =0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(nums,mid,threshold)==false){
                low=mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};