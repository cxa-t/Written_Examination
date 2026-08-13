// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;                         // 保存最终的层序遍历结果
        if (root == nullptr) return ret;                  // 空树直接返回空结果

        queue<TreeNode*> q;                              // 队列用于进行层序遍历
        q.push(root);                                    // 将根节点加入队列

        bool rev = false;                                // 标记当前层是否需要逆序存放

        while (!q.empty())                                // 队列不为空就继续遍历
        {
            int sz = q.size();                           // 记录当前层的节点数量
            vector<int> tmp(sz);                         // 提前创建当前层对应大小的数组

            for (int i = 0; i < sz; i++)                  // 遍历当前层所有节点
            {
                TreeNode* cur = q.front();               // 获取队头节点
                q.pop();                                 // 将当前节点移出队列

                int index = rev ? sz - 1 - i : i;        // 根据遍历方向计算存放位置
                tmp[index] = cur->val;                   // 将当前节点值放到正确位置

                if (cur->left)                            // 左孩子存在
                    q.push(cur->left);                   // 将左孩子加入队列
                if (cur->right)                           // 右孩子存在
                    q.push(cur->right);                  // 将右孩子加入队列
            }
            ret.push_back(tmp);                          // 保存当前层的遍历结果
            rev = !rev;                                  // 切换下一层的遍历方向
        }
        return ret;                                      // 返回最终结果
    }
};