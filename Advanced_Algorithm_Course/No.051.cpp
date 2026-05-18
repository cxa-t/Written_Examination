// https://leetcode.cn/problems/add-two-numbers/

//思路
//逆序存储，刚好相加的时候也是按照逆序进行相加的，所以就是按照顺序往下走，注意进位就好了

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(0);
        ListNode* ret = head;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int up = 0;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            int result = cur1->val + cur2->val + up;
            ret->next = new ListNode(result % 10);
            ret = ret->next;
            up = result / 10;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while (cur1 != nullptr)
        {
            int result = cur1->val + up;
            ret->next = new ListNode(result % 10);
            ret = ret->next;
            up = result / 10;
            cur1 = cur1->next;
        }
        while (cur2 != nullptr)
        {
            int result = cur2->val + up;
            ret->next = new ListNode(result % 10);
            ret = ret->next;
            up = result / 10;
            cur2 = cur2->next;
        }
        if (up) ret->next = new ListNode(up);
        ret = head->next;
        delete head;
        return ret;
    }
};