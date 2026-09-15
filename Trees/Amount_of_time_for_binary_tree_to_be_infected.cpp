// 2385
// Amount of Time for Binary Tree to be Infected
// Medium


#include<queue>
#include<unordered_map>
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
    int distance(unordered_map<TreeNode*,TreeNode*> &map, TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,int> vis;
        vis[target] = 1;
        int maxi = 0;
        while(!q.empty()){
            int size = q.size();
            int fl = 0;
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(map[node] && !vis[map[node]]){
                    fl = 1;
                    vis[map[node]] = 1;
                    q.push(map[node]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }

    TreeNode* bfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &map,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val==start) res = node;
            q.pop();
            if(node->left){
                map[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                map[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> map;
        TreeNode* target = bfs(root, map,start);
        int maxi = distance(map,target);
        return maxi;
    }
};