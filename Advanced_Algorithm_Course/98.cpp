// https://leetcode.cn/problems/validate-binary-search-tree/


class Solution
{
    // prev 记录中序遍历过程中，上一个访问过的节点值
    long prev = LONG_MIN;

public:
    // 判断一棵二叉树是否是合法的二叉搜索树
    bool isValidBST(TreeNode* root)
    {
        // 如果当前节点为空，空树也是合法二叉搜索树
        if (root == nullptr) return true;
        // 先递归判断左子树是否是合法二叉搜索树
        bool left = isValidBST(root->left);
        // 如果左子树不合法，整棵树直接不合法
        if (left == false) return false;
        // cur 表示当前节点是否满足二叉搜索树的中序递增要求
        bool cur = false;
        // 如果当前节点值大于上一个访问的节点值，说明当前节点合法
        if (root->val > prev)
            cur = true;
        // 如果当前节点不合法，直接返回 false
        if (cur == false) return false;
        // 更新 prev，让它记录当前节点值
        prev = root->val;
        // 再递归判断右子树是否是合法二叉搜索树
        bool right = isValidBST(root->right);
        // 左子树、当前节点、右子树都合法，整棵树才合法
        return cur && left && right;
    }
};