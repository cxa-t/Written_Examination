// https://leetcode.cn/problems/reverse-nodes-in-k-group/

//思路
//先求出总数，然后k个一组进行反转
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        // 1. 先求出需要逆序多少组
        int n = 0;
        ListNode* cur = head;
        while (cur)
        {
            cur = cur->next;
            n++;
        }
        n /= k;

        // 2. 重复 n 次: 长度为 k 的链表的逆序即可
        ListNode* newHead = new ListNode(0);
        ListNode* prev = newHead;
        cur = head;

        for (int i = 0; i < n; i++)
        {
            ListNode* tmp = cur;
            // 反转当前组的 k 个节点
            for (int j = 0; j < k; j++)
            {
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;
        }

        // 把不需要翻转的接上
        prev->next = cur;
        ListNode* result = newHead->next;
        delete newHead;
        return result;
    }
};