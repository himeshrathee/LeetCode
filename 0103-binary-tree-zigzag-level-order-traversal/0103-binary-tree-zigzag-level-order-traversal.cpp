/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int findlevel(TreeNode * root){
        if(root == NULL)return 0 ; 
        int l = findlevel(root->left) ; 
        int r= findlevel(root->right) ; 
        return 1 + max(l,r) ; 
    }
    void levelordertrav(TreeNode* root, vector<vector<int>>&lo){
      if(root == NULL)return ; 
      queue<TreeNode*>q; 
      q.push(root); 
      int i = 0; 
      while(!q.empty()){
        int sz= q.size() ;
        while(sz--){

        TreeNode* tp = q.front() ; 
        q.pop(); 
       lo[i].push_back(tp->val) ; 
     
       if(tp->left){
        q.push(tp->left) ; 
        
       }
       if(tp->right){
        q.push(tp->right); 
       }
        }
     i++ ; 
      }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = findlevel(root) ; 
        vector<vector<int>>levelorder(n,vector<int>()); 
        levelordertrav(root,levelorder) ; 
        for(int i = 0;i<n;i++){
            if(i % 2 != 0){
              reverse(levelorder[i].begin() , levelorder[i].end()) ; 
            }
        }
        return levelorder ; 
    }
};