// https://leetcode.cn/problems/sum-root-to-leaf-numbers/


class Solution
{
public:
    // 深度优先遍历，presum 表示从根节点到当前节点父节点组成的数字
    int dfs(TreeNode* root, int presum)
    {
        // 将当前节点的值拼接到已有数字后面
        presum = root->val + presum * 10;
        // 如果当前节点是叶子节点，说明形成了一条完整路径，返回这个数字
        if (root->left == nullptr && root->right == nullptr)
            return presum;
        // ret 用来累加当前节点下面所有路径形成的数字之和
        int ret = 0;
        // 如果左子树存在，就继续向左递归，并累加左子树路径和
        if (root->left) ret += dfs(root->left, presum);
        // 如果右子树存在，就继续向右递归，并累加右子树路径和
        if (root->right) ret += dfs(root->right, presum);
        // 返回当前子树所有根到叶子路径数字之和
        return ret;
    }

    // 计算从根节点到所有叶子节点形成的数字之和
    int sumNumbers(TreeNode* root)
    {
        // 如果树为空，路径和为 0
        if (root == nullptr) return 0;
        // 从根节点开始递归，初始已有数字为 0
        return dfs(root, 0);
    }
};