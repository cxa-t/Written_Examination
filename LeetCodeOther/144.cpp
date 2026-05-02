// https://leetcode.cn/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> ret;

        //每次循环都是访问一棵树的开始
        while (cur || !st.empty())
        {
            //访问左路节点  左路节点入栈模拟递归
            while (cur)
            {
                ret.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            //取左路节点的右子树访问
            TreeNode* rleft = st.top();
            st.pop();

            //循环子问题的访问  访问右子树
            cur = rleft->right;
        }
        return ret;
    }
};