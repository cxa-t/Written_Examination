// https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        // 如果链表为空，直接返回 {-1, -1}
        // 如果链表只有一个节点，也不可能有临界点
        if (head == nullptr || head->next == nullptr) return { -1, -1 };

        // first 记录第一个临界点的位置
        int first = -1;
        // last 记录上一个临界点的位置
        int last = -1;

        // mindis 记录两个相邻临界点之间的最小距离
        int mindis = INT_MAX;
        // prev 指向当前节点的前一个节点
        ListNode* prev = head;
        // cur 指向当前正在判断的节点
        ListNode* cur = head->next;
        // count 表示当前节点的位置，这里从 1 开始
        int count = 1;
        // cur 必须有下一个节点，才能判断它是不是临界点
        while (cur != nullptr && cur->next != nullptr)
        {
            // next 表示当前节点的后一个节点
            ListNode* next = cur->next;
            // 判断当前节点是否是局部最大值或局部最小值
            if ((cur->val > prev->val && cur->val > next->val) ||
                (cur->val < prev->val && cur->val < next->val))
            {
                // 如果这是第一个临界点
                if (first == -1)
                    // 记录第一个临界点的位置
                    first = count;
                else
                    // 更新相邻两个临界点之间的最小距离
                    mindis = min(mindis, count - last);
                // 更新上一个临界点的位置
                last = count;
            }
            // prev 向后移动
            prev = cur;
            // cur 向后移动
            cur = cur->next;
            // 当前节点位置加 1
            count++;
        }
        // 如果没有临界点，或者只有一个临界点，返回 {-1, -1}
        if (first == -1 || first == last) return { -1, -1 };
        // 最小距离是 mindis，最大距离是最后一个临界点位置减第一个临界点位置
        return { mindis, last - first };
    }
};