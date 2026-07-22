// https://leetcode.cn/problems/merge-two-sorted-lists/


class Solution
{
public:
    // 合并两个升序链表，并返回合并后的链表头节点
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        // 如果 l1 为空，直接返回 l2
        if (!l1) return l2;
        // 如果 l2 为空，直接返回 l1
        if (!l2) return l1;
        // 如果 l1 当前节点值小于等于 l2 当前节点值
        if (l1->val <= l2->val)
        {
            // l1 当前节点后面，接上 l1->next 和 l2 合并后的链表
            l1->next = mergeTwoLists(l1->next, l2);
            // 返回 l1 作为当前合并链表的头节点
            return l1;
        }
        // 如果 l2 当前节点值更小
        else
        {
            // l2 当前节点后面，接上 l1 和 l2->next 合并后的链表
            l2->next = mergeTwoLists(l1, l2->next);
            // 返回 l2 作为当前合并链表的头节点
            return l2;
        }
    }
};