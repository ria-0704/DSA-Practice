// Leetcode 48
// Rotate Image
// Difficulty: Medium

#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int top = 0;
        int left = 0;
        int bottom = n-1;
        int right = n-1;
        while(top<bottom){
        for(int i=0;i<right-left;i++){
            int temp = matrix[top][left+i];
            matrix[top][left+i] = matrix[bottom-i][left];
            matrix[bottom-i][left] = matrix[bottom][right-i];
            matrix[bottom][right-i] = matrix[top+i][right];
            matrix[top+i][right] = temp;
        }
        top++;
        right--;
        left++;
        bottom--;
        }

    }
};