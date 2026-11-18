// https://leetcode.cn/problems/add-two-numbers-ii/?envType=study-plan-v2&envId=programming-skills


/**
 * Definition for singly-linked list. // 单链表节点的定义
 * struct ListNode { // 定义链表节点结构体
 *     int val; // 存储当前节点的数值
 *     ListNode *next; // 指向下一个链表节点的指针
 *     ListNode() : val(0), next(nullptr) {} // 默认构造函数，将节点值初始化为0，后继指针初始化为空
 *     ListNode(int x) : val(x), next(nullptr) {} // 创建值为x的节点，并将后继指针初始化为空
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // 创建值为x的节点，并指定下一个节点
 * };
 */
class Solution // 定义题解类，使用链表反转和模拟加法解决两数相加问题
{
public: // 公有成员区域
    ListNode* ReverseList(ListNode* head) // 定义链表反转函数，使用头插法将原链表中的节点顺序反转
    {
        ListNode* newhead = new ListNode(); // 创建虚拟头节点，用来管理反转后的链表，初始next为空
        ListNode* cur = head; // 定义cur指针，指向原链表的头节点，用来遍历原链表
        while(cur) // 只要cur不为空，说明原链表还有节点没有处理，继续执行头插法
        {
            ListNode* nextnode = cur->next; // 提前保存当前节点的下一个节点，避免修改cur->next后丢失后续链表
            cur->next = newhead->next; // 将当前节点的next指针指向新链表的第一个有效节点
            newhead->next = cur; // 将当前节点插入虚拟头节点后面，使其成为反转后链表的第一个有效节点
            cur = nextnode; // 将cur移动到原链表的下一个节点，继续进行头插操作
        }
        ListNode* ret = newhead->next; // 保存反转后链表的真正头节点，跳过虚拟头节点
        delete newhead; // 释放动态申请的虚拟头节点，避免内存泄漏，不影响后面的有效节点
        return ret; // 返回反转后的链表头节点
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) // 将两个以高位在前方式存储数字的链表相加，返回结果链表
    {
        l1 = ReverseList(l1); // 反转第一个链表，将原本位于链表末尾的个位数字移动到头部，方便从低位开始计算
        l2 = ReverseList(l2); // 反转第二个链表，同样让个位数字位于头部，便于两个链表逐位相加
        ListNode* newhead = new ListNode; // 创建结果链表的虚拟头节点，后续通过头插法构建最终结果
        ListNode* cur1 = l1; // 定义cur1指针，指向第一个反转后的链表头节点，用来遍历第一个加数
        ListNode* cur2 = l2; // 定义cur2指针，指向第二个反转后的链表头节点，用来遍历第二个加数
        int upper = 0; // 定义进位变量，初始为0，用来保存上一位相加产生的进位
        while(cur1 && cur2) // 当两个链表都还有节点时，将两个链表对应位置的数字相加
        {
            int sum = cur1->val + cur2->val; // 计算两个链表当前节点的数值之和，暂时不包含上一位产生的进位
            ListNode* tmp = new ListNode((sum + upper) % 10); // 当前位的结果等于两个数字加上进位后对10取余，创建对应的结果节点
            tmp->next = newhead->next; // 将新节点的next指针指向结果链表原来的第一个有效节点，准备执行头插法
            newhead->next = tmp; // 将新节点插入结果链表头部，使计算出的低位数字逐渐向后移动
            upper = (upper + sum) / 10; // 计算当前位相加后产生的进位，如果结果达到10则进位为1，否则为0
            cur1 = cur1->next; // 第一个链表指针向后移动，准备计算下一位数字
            cur2 = cur2->next; // 第二个链表指针向后移动，准备计算下一位数字
        }
        while(cur1) // 如果第一个链表还有剩余节点，说明第一个数字的位数更多，需要继续处理剩余的高位
        {
            int sum = cur1->val + upper; // 将第一个链表当前节点的数值与上一位产生的进位相加
            ListNode* tmp = new ListNode(sum % 10); // 当前位的结果等于sum对10取余，创建存储当前位数字的新节点
            tmp->next = newhead->next; // 将新节点指向结果链表当前的第一个有效节点，准备头插
            newhead->next = tmp; // 将当前结果节点插入结果链表头部，保持最终结果的高位在前
            upper = sum / 10; // 更新进位，如果当前数字加上进位后达到10，则继续向更高位进位
            cur1 = cur1->next; // 将第一个链表指针向后移动，继续处理剩余节点
        }
        while(cur2) // 如果第二个链表还有剩余节点，说明第二个数字的位数更多，需要继续处理剩余的高位
        {
            int sum = cur2->val + upper; // 将第二个链表当前节点的数值与上一位产生的进位相加
            ListNode* tmp = new ListNode(sum % 10); // 当前位的结果等于sum对10取余，创建对应的新节点
            tmp->next = newhead->next; // 将新节点指向结果链表原来的第一个有效节点
            newhead->next = tmp; // 将新节点插入结果链表头部，保证结果链表中的高位数字位于前面
            upper = sum / 10; // 根据当前位相加的结果更新进位，准备处理更高位
            cur2 = cur2->next; // 将第二个链表指针向后移动，继续处理剩余节点
        }
        if(upper) // 如果所有节点处理完成后仍然存在进位，说明最终结果需要增加一个最高位
        {
            ListNode* tmp = new ListNode(upper); // 创建一个新节点保存最后的进位，通常这个进位为1
            tmp->next = newhead->next; // 将进位节点指向结果链表原来的第一个有效节点
            newhead->next = tmp; // 将进位节点插入结果链表头部，使其成为最终结果的最高位
        }
        ListNode* ret = newhead->next; // 保存结果链表真正的头节点，跳过虚拟头节点
        delete newhead; // 释放结果链表的虚拟头节点，避免内存泄漏，同时保留所有结果节点
        return ret; // 返回最终相加得到的结果链表，数字按照高位在前的顺序存储
    }
};
