// https://leetcode.cn/problems/merge-k-sorted-lists/


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

//法一 思路
//利用优先队列（堆），每次将多个链表的第一个节点加入堆中（必须非空）
//然后拿到堆顶最小的元素，也就是值最小的节点加入结果
class Solution
{
public:
    struct cmp
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (ListNode* l : lists) if (l) heap.push(l);
        ListNode* newnode = new ListNode();
        ListNode* tail = newnode;
        while (!heap.empty())
        {
            ListNode* cur = heap.top();
            heap.pop();
            tail->next = cur;
            tail = tail->next;
            if (cur->next) heap.push(cur->next);
        }
        tail = newnode->next;
        delete newnode;
        return tail;
    }
};

