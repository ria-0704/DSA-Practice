// 110
// Balanced Binary Tree
// Easy


#include<vector>
#include<math.h>
using namespace std;
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
    bool isBalanced(TreeNode* root) {
        if(ht(root)==-1) return false;
        else return true;
    }
    int ht(TreeNode* root){
        if(root==nullptr) return 0;
        int lh = ht(root->left);
        int rh = ht(root->right);
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
};