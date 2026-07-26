// https://leetcode.cn/problems/evaluate-boolean-binary-tree/


class Solution
{
public:
    // 计算布尔二叉树的最终结果
    bool evaluateTree(TreeNode* root)
    {
        // 如果当前节点是叶子节点，直接返回它的布尔值
        if (root->left == nullptr) return root->val;
        // 递归计算左子树的布尔结果
        auto left = evaluateTree(root->left);
        // 递归计算右子树的布尔结果
        auto right = evaluateTree(root->right);
        // 如果当前节点值为 2，表示或运算；否则表示与运算
        return root->val == 2 ? left | right : left & right;
    }
};