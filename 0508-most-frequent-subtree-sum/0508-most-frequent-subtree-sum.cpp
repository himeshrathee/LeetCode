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
    
    int  findsum(TreeNode * root , vector<int>&ans){
    if(root== NULL)return 0 ; 
    long long int  sum = root->val + findsum(root->left,ans) + findsum(root->right , ans) ; 
    ans.push_back(sum) ; 
    return (int)sum; 
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans ; 
       int a=  findsum(root,ans); 
       set<int>st ; 
        int maxi =-1e9 ; 
        map<int ,int>count ; 
        for( auto ele : ans){
            st.insert(ele) ; 
            count[ele]++ ; 
            if(count[ele] > maxi )maxi = count[ele] ; 
          
        } 
        int cnt = 0 ; 
        
        for(auto &[a,b] : count){
            if(b==maxi){cnt++; }

        }
vector<int> res;

for (auto &[sum, freq] : count) {
    if (freq == maxi)
        res.push_back(sum);
}

return res;

    }
};