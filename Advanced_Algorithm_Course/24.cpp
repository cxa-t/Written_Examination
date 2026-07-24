// https://leetcode.cn/problems/swap-nodes-in-pairs/


class Solution
{
public:
    // 两两交换链表中的相邻节点，并返回交换后的头节点
    ListNode* swapPairs(ListNode* head)
    {
        // 如果链表为空，或者只有一个节点，不需要交换，直接返回
        if (head == nullptr || head->next == nullptr) return head;
        // 递归处理从第三个节点开始的后续链表
        ListNode* tmp = swapPairs(head->next->next);
        // ret 指向当前这一组两个节点中的第二个节点，它会成为交换后的头
        ListNode* ret = head->next;
        // 让第二个节点指向第一个节点，完成当前这一对的交换
        ret->next = head;
        // 让第一个节点接上后面已经交换好的链表
        head->next = tmp;
        // 返回当前这一组交换后的头节点
        return ret;
    }
};