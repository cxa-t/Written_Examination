// https://leetcode.cn/problems/reorder-list/

//思路
//先找到链表中间考前的位置， 1 2 3 4 就找 2，1 2 3 4 5就找3
//找到之后把后半部分拆分出来 ，拆分出来后进行反转
//然后开始尾插 先插前半部分的，再插入后半部分的，前半部分可能是奇数个，最后单独处理最后一个节点

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
    ListNode* ListMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* ListRevrese(ListNode* head)
    {
        ListNode* newhead = new ListNode();
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = newhead->next;
            newhead->next = cur;
            cur = next;
        }
        ListNode* ret = newhead->next;
        delete newhead;
        return ret;
    }

    void reorderList(ListNode* head)
    {
        ListNode* mid = ListMid(head);
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        mid->next = nullptr;
        list2 = ListRevrese(list2);
        ListNode* newhead = new ListNode();
        ListNode* ret = newhead;
        while (list1 && list2)
        {
            ListNode* l1next = list1->next;
            ListNode* l2next = list2->next;
            list1->next = nullptr;
            list2->next = nullptr;
            ret->next = list1;
            ret = list1;
            ret->next = list2;
            ret = list2;
            list1 = l1next;
            list2 = l2next;
        }
        if (list1) ret->next = list1;
    }
};