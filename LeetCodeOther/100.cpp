// https://leetcode.cn/problems/same-tree/?envType=study-plan-v2&envId=top-interview-150


/**
 * Definition for a binary tree node. // 二叉树节点的定义
 * struct TreeNode { // 定义二叉树节点结构体
 *     int val; // 存储当前节点的值
 *     TreeNode *left; // 指向当前节点的左子节点
 *     TreeNode *right; // 指向当前节点的右子节点
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // 默认构造函数，将节点值初始化为0，左右子节点初始化为空指针
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 创建值为x的节点，左右子节点初始化为空指针
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // 创建值为x的节点，并指定左右子节点
 * };
 */
class Solution // 定义题解类，使用递归判断两棵二叉树是否完全相同
{
public: // 公有成员区域
    bool isSameTree(TreeNode* p, TreeNode* q) // 判断以p和q为根节点的两棵二叉树是否相同，要求对应位置的节点值相同且树的结构相同
    {
        if(p == nullptr || q == nullptr) // 如果p或q中至少有一个是空指针，说明至少有一棵树的当前位置没有节点
            return p == q; // 如果p和q都是nullptr，则说明当前位置的结构相同，返回true；如果只有一个是nullptr，则说明结构不同，返回false
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // 首先判断当前两个节点的值是否相同，然后递归比较两棵树的左子树和右子树，只有当前节点值相同、左子树相同、右子树也相同时，才返回true
    }
};