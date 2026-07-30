// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/


class Solution
{
public:
    // ret 用来保存第 k 小节点的值
    int ret = 0;
    // count 用来记录还需要访问多少个节点
    int count = 0;

    // 中序遍历二叉搜索树
    void dfs(TreeNode* root)
    {
        // 如果当前节点为空，或者已经找到第 k 小节点，直接返回
        if (root == nullptr || count == 0) return;
        // 先遍历左子树，因为 BST 左子树的值更小
        dfs(root->left);
        // 访问当前节点时，说明又访问到了一个更大的节点
        count--;
        // 如果 count 变成 0，说明当前节点就是第 k 小节点
        if (count == 0)
            ret = root->val;
        // 最后遍历右子树，因为 BST 右子树的值更大
        dfs(root->right);
    }

    // 返回二叉搜索树中第 k 小的元素
    int kthSmallest(TreeNode* root, int k)
    {
        // 初始化 count 为 k，表示还需要访问 k 个节点
        count = k;
        // 从根节点开始中序遍历
        dfs(root);
        // 返回第 k 小节点的值
        return ret;
    }
};