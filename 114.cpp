// 给你二叉树的根结点 root ，请你将它展开为一个单链表：

// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 

//method 1 : 寻找到当前节点的前驱节点
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return ;
        TreeNode* cur = root;
        while(cur != nullptr){
            if(cur -> left != nullptr){
                TreeNode* next = cur -> left;
                TreeNode* pre = next;
                while(pre -> right){
                    pre = pre -> right;
                }
                pre -> right = cur -> right;
                cur -> left = nullptr;
                cur -> right = next;
            }
            cur = cur -> right;
        }
    }
};
