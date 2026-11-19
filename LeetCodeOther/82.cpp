// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/



/**
 * Definition for singly-linked list. // 单链表节点的定义
 * struct ListNode { // 定义链表节点结构体
 *     int val; // 存储当前节点的数值
 *     ListNode *next; // 指向链表中的下一个节点
 *     ListNode() : val(0), next(nullptr) {} // 默认构造函数，将节点值初始化为0，next初始化为空指针
 *     ListNode(int x) : val(x), next(nullptr) {} // 创建值为x的节点，并将next初始化为空指针
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // 创建值为x的节点，并指定它的下一个节点
 * };
 */
class Solution // 定义题解类，使用双指针和尾插法删除排序链表中所有重复的元素
{
public: // 公有成员区域
    ListNode* deleteDuplicates(ListNode* head) // 删除排序链表中所有出现重复的节点，只保留原链表中出现一次的元素
    {
        if(head == nullptr) return nullptr; // 如果原链表为空，说明没有节点需要处理，直接返回空指针
        ListNode* newhead = new ListNode(); // 创建虚拟头节点，用来保存删除重复元素后的新链表，方便统一处理头节点
        ListNode* tail = newhead; // 定义尾指针tail，初始指向虚拟头节点，用来通过尾插法添加符合要求的新节点
        ListNode* left = head; // 定义左指针left，指向当前需要检查的节点，也就是当前待判断数字的第一个节点
        ListNode* right = left->next; // 定义右指针right，指向left的下一个节点，用来判断当前数字是否重复
        while(left) // 只要left不为空，说明原链表还有节点没有处理，继续遍历
        {
            if(right == nullptr || left->val != right->val) // 如果right为空，或者left与right的数值不同，说明left对应的数字只出现了一次，可以保留
            {
                ListNode* tmp = new ListNode(left->val); // 创建一个新节点tmp，将当前不重复节点的数值保存到新节点中
                tail->next = tmp; // 将新节点tmp连接到结果链表的末尾，实现尾插操作
                tail = tmp; // 更新尾指针tail，使其指向刚刚插入的新节点，方便下一次继续尾插
                left = right; // 将左指针移动到下一个待处理的节点，准备判断下一个数字是否重复
                right = right ? right->next : nullptr; // 如果right不为空，就让right移动到下一个节点；否则将right设置为空，避免访问空指针
            }
            else // 如果left和right都不为空且数值相等，说明当前数字至少出现两次，需要删除所有等于该数字的节点
            {
                while(right && right->val == left->val) // 当right不为空，并且right的数值与left相同时，说明仍然处于当前重复数字的连续区间
                    right = right->next; // 不断向后移动right，跳过所有与left数值相同的节点，直到找到不同的数字或者到达链表末尾
                left = right; // 当前重复数字已经全部跳过，将left移动到下一个不同数字的节点，开始处理下一组数字
                right = right ? right->next : nullptr; // 将right移动到left的下一个节点；如果left已经为空，则right也设置为空
            }
        }
        ListNode* ret = newhead->next; // 获取结果链表真正的头节点，跳过不存储有效数据的虚拟头节点
        delete newhead; // 释放动态申请的虚拟头节点，避免内存泄漏，同时不影响后面新创建的有效节点
        return ret; // 返回删除所有重复数字后的新链表头节点
    }
};
