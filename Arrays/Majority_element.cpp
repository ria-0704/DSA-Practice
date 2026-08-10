// Leetcode 169
// Majority Element
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // int n = nums.size();
        // for(int i = 0;i<n;i++){
        //     if(mp.find(nums[i]) == mp.end()){
        //         mp[nums[i]] = 1;
        //     }
        //     else{
        //         mp[nums[i]]++;
        //     }
        // }
        // int majority = n/2;
        // int ans = 0;
        // for(auto x:mp){
        //     if(x.second>majority) ans = x.first ;
        // }
        // return ans;


        //Boyer-Moore Voting Algorithm
        int n = nums.size();
        int ele = nums[0];
        int count = 1;
        for(int i = 1;i<n;i++){
            if(count==0){
                ele = nums[i];
                count = 1;
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }
        int c = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                c++;
            }
        }
        int ans = 0;
        if(c>(n/2)){
            ans = ele;
        }
        return ans;
    }
};