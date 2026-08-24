// Leetcode 1011
// Capacity to ship packages within D days
// Difficulty: Medium


#include<vector>
using namespace std;
class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int load=0;
        int days = 1;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]+load>cap){
                days+=1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        int n= weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>low) low = weights[i];
            high += weights[i];
        }
        while(low<=high){
            int mid = (low+high)/2;
            int nod = findDays(weights,mid);
            if(nod<=days) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};