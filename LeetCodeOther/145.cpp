// https://leetcode.cn/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur || !st.empty())
        {
            //先访问左路节点
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st.top();
            // top结点的右为空 或者 上一个访问结点等于他的右孩子         
            // 那么说明(空)不用访问 或者(不为空)右子树已经访问过了            
            // 那么说明当前结点左右子树都访问过了，可以访问当前结点了
            if (top->right == nullptr || prev == top->right)
            {
                ret.push_back(top->val);
                st.pop();
                prev = top;
            }
            else
            {
                //循环处理子问题
                cur = top->right;
            }
        }
        return ret;
    }
};