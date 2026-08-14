// https://leetcode.cn/problems/maximum-width-of-binary-tree/

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

class Solution
{
public:
    int widthOfBinaryTree(TreeNode* root)                 // 计算二叉树的最大宽度
    {
        vector<pair<TreeNode*, unsigned int>> q;          // 保存当前层节点及其对应编号

        q.push_back({ root, 1 });                           // 将根节点以编号1加入当前层

        unsigned int ret = 1;                             // 记录二叉树的最大宽度

        while (q.size())                                   // 当前层还有节点时继续遍历
        {
            auto& frontNum = q[0].second;                 // 获取当前层最左节点的编号

            auto& backNum = q.back().second;              // 获取当前层最右节点的编号

            ret = max(ret, backNum - frontNum + 1);       // 根据左右节点编号计算当前层宽度

            vector<pair<TreeNode*, unsigned int>> tmp;    // 保存下一层的节点及其编号

            for (auto& e : q)                              // 遍历当前层的所有节点
            {
                if (e.first->left != nullptr)              // 当前节点存在左孩子
                    tmp.push_back({ e.first->left, e.second * 2 }); // 左孩子编号设为父节点编号的2倍

                if (e.first->right != nullptr)             // 当前节点存在右孩子
                    tmp.push_back({ e.first->right, e.second * 2 + 1 }); // 右孩子编号设为父节点编号的2倍加1
            }

            q = tmp;                                      // 将下一层更新为新的当前层
        }

        return ret;                                       // 返回二叉树的最大宽度
    }
};