//路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
private:
    int maxsum = INT_MIN;
public:
    int maxG(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int leftG = max(0, maxG(node -> left));
        int rightG = max(0, maxG(node -> right));
        int curG = node -> val + max(leftG, rightG);
        maxsum = max(maxsum, node -> val + leftG +rightG);
        return curG;
    }
    int maxPathSum(TreeNode* root) {
        maxG(root);
        return maxsum;
    }
};
