// https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/


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
    // 将二进制链表表示的数字转换成十进制整数
    int getDecimalValue(ListNode* head) 
    {
        // ans 用来保存当前转换得到的十进制结果
        int ans = 0;
        // 从链表头节点开始，依次遍历每一个节点
        while (head) 
        {
            // 每读入一位二进制数，就让当前结果乘 2 再加上当前位
            ans = ans * 2 + head->val;
            // 指针移动到下一个链表节点
            head = head->next;
        }
        // 返回最终转换得到的十进制整数
        return ans;
    }
};
