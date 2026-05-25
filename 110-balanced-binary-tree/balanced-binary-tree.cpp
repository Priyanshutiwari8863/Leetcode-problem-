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
public:
     int checkaH(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lH= checkaH(root->left);
        if(lH == -1) return -1;

        int RH= checkaH(root->right);
        if(RH == -1) return -1;

        if(abs(lH - RH) >1) return -1;
        
        return 1+ max(lH,RH);
     }

    bool isBalanced(TreeNode* root) {
         return checkaH(root) != -1;

        
    }
};