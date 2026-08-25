// Leetcode 410
// Split Array Largest Sum
// Difficulty: Hard

#include<vector>
using namespace std;
#include <algorithm>  
#include <numeric> 
class Solution {
public:
    int countStudents(vector<int> &arr, int pages){
        int students = 1;
        long long pagesStudent = 0;
        for(int i=0;i<arr.size();i++){
            if(pagesStudent + arr[i] <= pages){
                pagesStudent += arr[i];
            }
            else{
                students += 1;
                pagesStudent = arr[i];
            }
        }
        return students;
    }
    int findPages(vector<int> &arr, int n, int m){
        if(m>n) return -1;
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0LL);
        while(low<=high){
            int mid = (low+high)/2;
            int student = countStudents(arr,mid);
            if(student > m){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};