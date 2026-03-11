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
    void allPaths(TreeNode* root,string path, vector<string> &ans){
        if(root->left == NULL && root->right == NULL){//base case
            ans.push_back(path);
            return;
        }
        if(root->left){// check left val extis or not
            allPaths(root->left,path +"->"+to_string(root->left->val),ans);
        }
         if(root->right){// check left val extis or not
            allPaths(root->right,path +"->"+to_string(root->right->val),ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);// convert in to string
        allPaths(root,path,ans); // call helper function
        return ans;
        
    }
};