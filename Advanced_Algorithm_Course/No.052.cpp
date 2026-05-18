// https://leetcode.cn/problems/swap-nodes-in-pairs/

//思路：
//画图
//画出四个节点的图 照着图写代码
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
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;

        ListNode* newhead = new ListNode();
        newhead->next = head;

        ListNode* prev = newhead;
        ListNode* cur = prev->next;
        ListNode* next = cur->next;
        ListNode* nnext = next->next;

        while (cur && next)
        {
            cur->next = nnext;
            next->next = cur;
            prev->next = next;
            // 改变下一次的节点顺序
            prev = cur;
            cur = nnext;
            if (nnext) next = nnext->next;
            if (next) nnext = next->next;
        }

        ListNode* ret = newhead->next;
        delete newhead;
        return ret;
    }
};