// Leetcode 3731
// Finding Missing Element
// Difficulty: Easy

#include<vector>
using namespace std;
#include<climits>
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max = nums[i];
            }
            if(nums[i]<min){
                min = nums[i];
            }
        }
        vector<int> v;
        int hash[1000] = {0};
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i = min;i<=max;i++){
            if(hash[i]==0){
                v.push_back(i);
            }
        }
        return v;
    }
};