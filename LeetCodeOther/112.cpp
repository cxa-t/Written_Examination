//  https://leetcode.cn/problems/path-sum/?envType=study-plan-v2&envId=top-interview-150


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
class Solution // 定义题解类，使用递归判断二叉树中是否存在满足目标和的根节点到叶子节点的路径
{
public: // 公有成员区域
    bool hasPathSum(TreeNode* root, int targetSum) // 判断是否存在一条从根节点到叶子节点的路径，使路径上所有节点的值之和等于targetSum
    {
        if(root == nullptr) // 如果当前节点为空，说明当前位置不存在节点，无法构成有效的根节点到叶子节点的路径
        {
            return false; // 空节点不能作为有效路径的终点，因此直接返回false
        }
        targetSum -= root->val; // 将目标和减去当前节点的值，表示接下来只需要在剩余路径中找到总和等于targetSum的节点
        if(root->left == nullptr && root->right == nullptr) // 如果当前节点的左子节点和右子节点都为空，说明当前节点是叶子节点，已经走到当前路径的终点
        {
            return targetSum == 0; // 如果剩余目标和等于0，说明从根节点到当前叶子节点的路径和恰好等于原始目标值，返回true；否则返回false
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum); // 分别递归检查左子树和右子树是否存在满足剩余目标和的路径，只要其中一条路径满足条件就返回true，否则返回false
    }
};
