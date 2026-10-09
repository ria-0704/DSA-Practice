// 124
// Binary Tree Maximum Path Sum
// Hard


#include<vector>
using namespace std;
#include<climits>
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        height(root,sum);
        return sum;
    }
    int height(TreeNode* node, int& sum){
        if(node==nullptr) return 0;
        int lh = height(node->left,sum);
        int rh = height(node->right,sum);
        lh = max(0,lh);
        rh = max(0,rh);
        sum = max(sum, node->val+lh+rh);
        return node->val+max(lh,rh);
    }
};