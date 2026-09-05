// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/


/* 
// Definition for a Node. 
class Node { 
public: 
    int val;                                      // 保存当前节点的值
    vector<Node*> children;                       // 保存当前节点的所有子节点
    Node() {}                                     // 默认构造一个节点
    Node(int _val) {                              // 使用节点值构造节点
        val = _val;                               // 初始化当前节点的值
    } 
    Node(int _val, vector<Node*> _children) {     // 使用节点值和子节点数组构造节点
        val = _val;                               // 初始化当前节点的值
        children = _children;                     // 初始化当前节点的子节点
    } 
}; 
*/ 
class Solution { 
public: 
    vector<vector<int>> levelOrder(Node* root)     // 返回N叉树的层序遍历结果
    { 
        queue<Node*> q;                            // 使用队列保存待遍历的节点
        if(!root) return {};                       // 空树直接返回空结果
        q.push(root);                              // 将根节点加入队列
        vector<vector<int>> ret;                   // 保存每一层的遍历结果
        while(q.size())                            // 队列不为空时继续层序遍历
        { 
            int sz = q.size();                     // 记录当前层的节点数量
            vector<int> tmp;                       // 保存当前层所有节点的值
            for(int i = 0; i < sz; i++)            // 遍历当前层的所有节点
            { 
                Node* t = q.front();               // 获取当前队头节点
                q.pop();                           // 将当前节点移出队列
                tmp.push_back(t->val);             // 保存当前节点的值
                for(Node* e : t->children) if(e) q.push(e); // 将当前节点的所有非空子节点加入队列
            } 
            ret.push_back(tmp);                    // 将当前层结果加入最终结果
        } 
        return ret;                                // 返回N叉树的层序遍历结果
    } 
};