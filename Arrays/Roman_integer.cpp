// Leetcode 13
// Roman Integer
// Difficulty: Easy


#include<string>
using namespace std;
class Solution {
public:
    int value(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        int n = s.size();
        int j = 1;
        while(j<n){
            if(value(s[i])<value(s[j])){
                ans -= value(s[i]);
            }
            else{
                ans += value(s[i]);
            }
            i++;
            j++;
        }
        ans += value(s[n-1]);
        return ans;
    }
};