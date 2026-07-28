// https://leetcode.cn/problems/binary-tree-pruning/


class Solution
{
public:
    // 删除所有不包含 1 的子树，并返回修剪后的根节点
    TreeNode* pruneTree(TreeNode* root)
    {
        // 如果当前节点为空，直接返回空
        if (root == nullptr) return nullptr;

        // 递归修剪当前节点的左子树
        root->left = pruneTree(root->left);
        // 递归修剪当前节点的右子树
        root->right = pruneTree(root->right);
        // 如果当前节点是叶子节点，并且值为 0，说明这棵子树不包含 1，需要删除
        if (root->left == nullptr && root->right == nullptr && root->val == 0)
        {
            // 不主动 delete，只是让当前节点从树中断开
            root = nullptr;
        }
        // 返回修剪后的当前子树根节点
        return root;
    }
};