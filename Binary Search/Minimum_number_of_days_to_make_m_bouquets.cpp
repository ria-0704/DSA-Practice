// Leetcode 1482
// Minimum Number of Daysto make m Bouquets
// Difficulty: Medium


#include<vector>
using namespace std;
class Solution {
public:
    bool possible(vector<int> bloomDay,int day, int m,int k){
        int count = 0;
        int num = 0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day) count++;
            else{
                num += (count/k);
                count = 0;
            }
        }
        num += (count/k);
        return num>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int min = 0;
        int max = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]>max) max = bloomDay[i];
            if(bloomDay[i]<min) min = bloomDay[i];
        }
        int ans = -1;
        int low = min;
        int high = max;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)==true){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};