// Leetcode 229
// Majority Element 2
// Difficulty: Medium

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     if(mp.find(nums[i])==mp.end()){
        //         mp[nums[i]] = 1;
        //     }
        //     else{
        //         mp[nums[i]]++;
        //     }
        // }
        // vector<int> ans;
        // int majority = n/3;
        // for(auto x:mp){
        //     if(x.second>majority){
        //         ans.push_back(x.first);
        //     }
        // }
        // return ans;

        //this approach took O(n) time and space

        //optimal solution to reduce space to O(1)
        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;
        int n = nums.size();
        for(auto num:nums){
            if(num==candidate1) count1++;
            else if(num == candidate2) count2++;
            else if(count1==0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2==0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto num:nums){
            if(num==candidate1) count1++;
            else if(num==candidate2) count2++;
        }
        vector<int> ans;
        if(count1>n/3) ans.push_back(candidate1);
        if(count2>n/3) ans.push_back(candidate2);
        return ans;
    }
};