// Leetcode 128
// Longest Consecutive sequence
// Difficulty: Medium

#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }

        int maxlen = 0;

        for (int x : st) {
            
            if (st.find(x - 1) == st.end()) {
                int current = x;
                int len = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    len++;
                }

                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};