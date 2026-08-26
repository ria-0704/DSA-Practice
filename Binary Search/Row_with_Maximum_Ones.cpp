// Leetcode 2643
// Row with Maximum Ones
// Difficulty: Easy

#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
    int lowerBound(vector<int> arr,int n,int x){
        sort(arr.begin(),arr.end());
        int low=0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt_max = 0;
        int index = 0;
        for(int i=0;i<n;i++){
            int cnt_ones = m - lowerBound(mat[i],m,1);
            if(cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return {index,cnt_max};
    }
};