// 98
// Validate Binary Search Tree
// Medium

#include<vector>
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
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int n = v.size();
        for(int i=1;i<n;i++){
            if(v[i-1]>=v[i]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};