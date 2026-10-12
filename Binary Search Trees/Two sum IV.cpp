// 653
// Two sum IV - Input in a BST
// Easy

#include<vector>
#include<map>
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int complement = k - v[i];
            if(mp.find(complement) != mp.end()) return true;
            mp[v[i]] = i;
        }
        return false;
    }
    void inorder(TreeNode* root,vector<int>& v){
        if(root==nullptr) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
};