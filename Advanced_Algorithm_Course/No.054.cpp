// https://leetcode.cn/problems/reverse-nodes-in-k-group/

//思路
//先判断有多少组
//然后每个组进行链表翻转
//每次记录需要头插的伪头节点
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
        // 统计总数
        ListNode* cur = head;
        int n = 0;
        while (cur)
        {
            n++;
            cur = cur->next;
        }
        if (n < k) return head;
        //共有n组需要逆序
        n /= k;

        ListNode* newhead = new ListNode();
        newhead->next = nullptr;
        cur = head;
        ListNode* prev = newhead;
        for (int i = 0; i < n; i++)
        {
            ListNode* tmp = cur;//记录下一次翻转需要的伪头节点
            int count = k;//每一组k个也就执行k次
            while (count)
            {
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                count--;
                cur = next;
            }
            prev = tmp;//每一组完之后，下一次翻转的头节点应该是当前这组的第一个节点，也就是一开始记录的第一个节点
        }
        prev->next = cur;
        ListNode* ret = newhead->next;
        delete newhead;//删除多申请的空间
        return ret;
    }
};