// https://leetcode.cn/problems/reverse-linked-list/


class Solution
{
public:
    // 反转单链表，并返回反转后的新头节点
    ListNode* reverseList(ListNode* head)
    {
        // 如果链表为空，或者只有一个节点，直接返回当前节点
        if (head == nullptr || head->next == nullptr) return head;
        // 递归反转 head 后面的链表，并拿到反转后的新头节点
        ListNode* newhead = reverseList(head->next);
        // 让 head 的下一个节点反过来指向 head
        head->next->next = head;
        // 将 head 的 next 置空，避免形成环
        head->next = nullptr;
        // 返回反转后链表的新头节点
        return newhead;
    }
};