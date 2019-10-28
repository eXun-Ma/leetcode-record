/*
双指针法：
使用快慢指针，快指针一次走2步，慢指针一次走1步
以环的大小大于从表头到循环点的距离为例说明：
1.假设从链表到环的距离为n，则快指针到达环的时候走了n步，慢指针此时位于n/2；
2.慢指针到达环的时候，快指针已经在环里面走了n步；
3.设环的大小为n+b，此时慢指针进入环并走b步，此时快指针走了2b步，快指针已经在环里面走了(n+2b)步，相当于1圈+b步，此时快慢指针相遇，距离入环处b步距离，接下去还要走n步重新回到入环处；
4.重新定义一个指针指向表头，另一指针指向与快慢指针相遇点，两个指针同时走n步即可到达入环处。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return NULL;
        ListNode *fast=head->next->next,*slow=head->next;
        while(fast!=slow){
            if(fast==NULL||fast->next==NULL)//一定要先判断是否为NULL
                return NULL;
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *flag=head;
        while(flag!=fast){
            flag=flag->next;
            fast=fast->next;
        }
        return flag;
    }
};
