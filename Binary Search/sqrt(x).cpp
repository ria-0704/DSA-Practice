// Leetcode 69
// Sqrt(x)
// Difficulty: Easy

#include<vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 1;
        while(low<=high){
            int mid = (low+high)/2;
            if((long long)mid*mid<=x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};