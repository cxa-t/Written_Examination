//  https://leetcode.cn/problems/invert-binary-tree/?envType=study-plan-v2&envId=top-interview-150



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
class Solution // 定义题解类，使用递归和后序遍历的思想翻转二叉树
{
public: // 公有成员区域
    TreeNode* invertTree(TreeNode* root) // 翻转以root为根节点的二叉树，将每个节点的左子树和右子树交换，并返回翻转后的根节点
    {
        if(root == nullptr) return nullptr; // 如果当前节点为空，说明没有需要翻转的节点，直接返回空指针，作为递归终止条件
        if(root->left == nullptr && root->right == nullptr) return root; // 如果当前节点是叶子节点，说明左右子节点都为空，不需要交换，直接返回当前节点
        invertTree(root->left); // 递归翻转当前节点的左子树，将左子树中每个节点的左右子节点进行交换
        invertTree(root->right); // 递归翻转当前节点的右子树，将右子树中每个节点的左右子节点进行交换
        TreeNode* tmp = root->right; // 定义临时指针tmp，保存当前节点原来的右子树，防止交换过程中丢失右子树的地址
        root->right = root->left; // 将当前节点的左子树赋值给右子树指针，使原来的左子树移动到右边
        root->left = tmp; // 将临时保存的原右子树赋值给左子树指针，完成当前节点左右子树的交换
        return root; // 当前节点及其左右子树都已经完成翻转，返回当前节点指针作为翻转后子树的根节点
    }
};
