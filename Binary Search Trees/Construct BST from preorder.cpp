// 1008
// Construct Binary Search Tree from preorder Traversal
// Medium


#include<vector>
#include<map>
using namespace std;
#include<algorithm>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
    TreeNode* build(vector<int> preorder, int ps, int pe, vector<int> inorder, int is, int ie, map<int,int>& mp){
        if(ps>pe||is>ie) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot-is;
        root->left = build(preorder,ps+1,ps+numsLeft,inorder,is,inRoot-1,mp);
        root->right = build(preorder,ps+numsLeft+1,pe,inorder,inRoot+1,ie,mp);
        return root;
    }
};