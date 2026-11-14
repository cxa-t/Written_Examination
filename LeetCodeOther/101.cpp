// https://leetcode.cn/problems/symmetric-tree/?envType=study-plan-v2&envId=top-interview-150


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
class Solution // 定义题解类，使用递归判断二叉树是否轴对称
{
public: // 公有成员区域
    bool isSymmetric(TreeNode* root) // 判断以root为根节点的二叉树是否关于中心轴对称
    {
        if(root == nullptr) // 如果根节点为空，说明这是一棵空树，空树本身就是对称的
            return true; // 直接返回true
        return recur(root->left, root->right); // 从根节点的左右子节点开始比较，判断左子树和右子树是否互为镜像
    }
    bool recur(TreeNode* L, TreeNode* R) // 定义递归函数，判断以L和R为根节点的两棵子树是否互为镜像
    {
        if(L == nullptr && R == nullptr) return true; // 如果左右两个节点都为空，说明当前位置的结构完全对称，返回true
        if(L == nullptr || R == nullptr || L->val != R->val) return false; // 如果只有一个节点为空，说明两边结构不对称；或者两个节点的值不相等，也说明不对称，返回false
        return recur(L->left, R->right) && recur(L->right, R->left); // 递归比较左子树的左节点与右子树的右节点，以及左子树的右节点与右子树的左节点，只有两组都对称，当前两棵子树才互为镜像
    }
};