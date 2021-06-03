//Morris 中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        while(root){
            if(root -> left){
                TreeNode* pre = root -> left;
                while(pre -> right && pre -> right != root){
                    pre = pre -> right;
                }
                if(pre -> right == nullptr){
                    pre -> right = root;
                    root = root -> left;
                }else{
                    ans.push_back(root -> val);
                    pre -> right = nullptr;
                    root = root -> right;
                }

            }else{
                ans.push_back(root -> val);
                root = root -> right;
            }
        }
        return ans;
    }
};
