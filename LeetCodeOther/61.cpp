// https://leetcode.cn/problems/rotate-list/?envType=study-plan-v2&envId=top-interview-150

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == nullptr || head->next == nullptr || k == 0) return head; // 空链表、单节点链表或不旋转时直接返回
        ListNode* cur = head; // 用于遍历链表
        ListNode* tail = nullptr; // 记录链表尾节点
        int count = 0; // 统计链表长度
        while(cur)
        {
            count++; // 节点数量加一
            tail = cur; // 更新尾节点
            cur = cur->next; // 移动到下一个节点
        }
        tail->next = head; // 将链表首尾相连，形成环形链表
        k %= count; // 去掉完整旋转的次数，避免重复操作
        int step = count - k - 1; // 计算新尾节点需要向后移动的步数
        ListNode* newtail = head; // 从原头节点开始寻找新尾节点
        while(step--)
        {
            newtail = newtail->next; // 向后移动，直到找到新尾节点
        }
        ListNode* newhead = newtail->next; // 新尾节点的下一个节点就是新头节点
        newtail->next = nullptr; // 断开环形链表，恢复普通链表结构
        return newhead; // 返回旋转后的新头节点
    }
};