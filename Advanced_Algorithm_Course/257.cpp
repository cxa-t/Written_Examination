// https://leetcode.cn/problems/binary-tree-paths/


class Solution
{
public:
    // ret 用来保存所有从根节点到叶子节点的路径
    vector<string> ret;
    // 深度优先遍历二叉树，path 表示当前已经走过的路径
    void dfs(TreeNode* root, string path)
    {
        // 如果当前节点为空，直接返回
        if (root == nullptr) return;
        // 将当前节点的值加入路径中
        path += to_string(root->val);
        // 如果当前节点是叶子节点，说明找到了一条完整路径
        if (root->left == nullptr && root->right == nullptr)
        {
            // 将当前完整路径加入结果数组
            ret.push_back(path);
            // 当前路径处理结束，返回上一层
            return;
        }
        // 如果还不是叶子节点，就在当前节点后面加上路径连接符
        path += "->";
        // 继续递归遍历左子树
        dfs(root->left, path);
        // 继续递归遍历右子树
        dfs(root->right, path);
    }
    // 返回二叉树中所有从根节点到叶子节点的路径
    vector<string> binaryTreePaths(TreeNode* root)
    {
        // path 用来记录当前递归路径
        string path;
        // 如果根节点为空，直接返回空结果
        if (root == nullptr) return ret;
        // 从根节点开始进行深度优先遍历
        dfs(root, path);
        // 返回所有根到叶子节点路径
        return ret;
    }
};