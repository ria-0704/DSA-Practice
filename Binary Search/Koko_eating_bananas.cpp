// Leetcode 875
// Koko Eating Bananas
// Difficulty: Medium

#include<vector>
using namespace std;
#include<math.h>
class Solution {
public:
    long long totalHours(vector<int> v,int hourly){
        long long total = 0;
        int n = v.size();
        for(int i=0;i<n;i++){
            total += ceil((double)v[i]/hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = 0;
        for(int i=0;i<n;i++){
            if(piles[i]>max) max = piles[i];
        }
        int low = 1;
        int high = max;
        while(low<=high){
            int mid = (low+high)/2;
            long long totalH = totalHours(piles,mid);
            if(totalH<=h){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};