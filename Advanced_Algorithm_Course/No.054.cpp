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


//法二
//利用归并的思路进行合并
class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right)
    {
        if (left > right) return nullptr;
        if (left == right) return lists[left];

        int mid = (left + right) >> 1;

        ListNode* pleft = merge(lists, left, mid);
        ListNode* pright = merge(lists, mid + 1, right);

        return merge2list(pleft, pright);
    }
    ListNode* merge2list(ListNode* pleft, ListNode* pright)
    {
        if (pleft == nullptr) return pright;
        if (pright == nullptr) return pleft;

        ListNode* newhead = new ListNode();
        ListNode* tail = newhead;
        while (pleft && pright)
        {
            if (pleft->val <= pright->val)
            {
                tail->next = pleft;
                pleft = pleft->next;
            }
            else
            {
                tail->next = pright;
                pright = pright->next;
            }
            tail = tail->next;
        }
        if (pleft) tail->next = pleft;
        if (pright) tail->next = pright;

        tail = newhead->next;
        delete newhead;
        return tail;
    }
};