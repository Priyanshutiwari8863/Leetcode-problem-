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
      bool isIdentical(TreeNode* p,TreeNode* q){
        if(p==NULL || q == NULL){ //Dono NULL → true, ek null ek nhi to false;
            return p==q;
        }
        bool isLeftSame = isIdentical(p->left,q->left);
        bool isRightSame = isIdentical(p->right, q->right);
        return isLeftSame && isRightSame && p->val== q->val;
      }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL){
            return root == subRoot; // dono same huaa to true;
        }
        if(root->val == subRoot->val && isIdentical(root,subRoot)){// for maching ke liye 
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);// dono me koi same ho to true de do thise code is recursive search karne ke liye hai yadi left me mil gya to right call nhi hoga
        
    }
};