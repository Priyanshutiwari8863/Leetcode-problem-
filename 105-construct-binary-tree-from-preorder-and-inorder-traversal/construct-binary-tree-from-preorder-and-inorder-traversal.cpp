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

    // Function to search the index of value in inorder array
    int search(vector<int>& inorder, int left , int right, int val){
        for(int i = left; i <= right; i++){
            if(inorder[i] == val){
                return i;   // return index where value found
            }
        }
        return -1;          // if value not found
    }

    //  helper function to construct the tree
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){

        // Base condition: if range is invalid
        if(left > right){
            return NULL;
        }

        // Create root node using preorder
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Find the root index in inorder array
        int inIdx = search(inorder, left, right, preorder[preIdx]);

        // Move to next preorder element
        preIdx++;

        // Build left subtree
        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);

        // Build right subtree
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        // Return constructed subtree
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preIdx = 0;  // index for preorder traversal

        // Call recursive helper function
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};