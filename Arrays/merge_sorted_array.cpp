// Leetcode 88
// Merge Sorted Array
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        for(int i=0; i<m;i++){
            v.push_back(nums1[i]);
        }
        int j=0;
        int k=0;
        int i=0;
        while(j<m and k<n){
            if(v[j]<=nums2[k]){
                nums1[i] = v[j];
                j++;
            }
            else{
                nums1[i] = nums2[k];
                k++;
            }
            i++;
        }
        while(j<m){
            nums1[i] = v[j];
            j++;
            i++;
        }
        while(k<n){
            nums1[i] = nums2[k];
            k++;
            i++;
        }
    }
};