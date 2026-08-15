// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/


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
    vector<int> largestValues(TreeNode* root)           // 返回二叉树每一层的最大值
    {
        vector<int> ret;                                // 保存每一层的最大值

        if (root == nullptr) return ret;                  // 空树直接返回空结果

        queue<TreeNode*> q;                             // 使用队列进行层序遍历
        q.push(root);                                    // 将根节点加入队列

        while (q.size())                                  // 队列不为空时继续遍历
        {
            int sz = q.size();                           // 记录当前层的节点数量
            int tmp = INT_MIN;                           // 记录当前层的最大值
            for (int i = 0; i < sz; i++)                  // 遍历当前层的所有节点
            {
                TreeNode* cur = q.front();               // 获取当前队头节点
                q.pop();                                 // 将当前节点移出队列
                tmp = max(cur->val, tmp);                // 更新当前层的最大值
                if (cur->left) q.push(cur->left);         // 左孩子存在则加入队列
                if (cur->right) q.push(cur->right);       // 右孩子存在则加入队列
            }
            ret.push_back(tmp);                          // 将当前层最大值加入结果集
        }
        return ret;                                      // 返回每一层的最大值
    }
};