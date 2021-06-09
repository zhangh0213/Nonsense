//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 

//1 递归归并

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode* right = getmid(head);
        head = sortList(head);
        right = sortList(right);
        head = merge(head, right);
        return head;
    }
    ListNode* getmid(ListNode* head){
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode* fast = head, *slow = head, *pre;
        while(fast && fast -> next){
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        pre -> next = nullptr;
        return slow;
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* pre = new ListNode(head1 -> val - 1, head1);
        ListNode* cur = pre;
        while(head1 && head2){
            if(head2 -> val <= head1 -> val){
                cur -> next = head2;
                head2 = head2 -> next;
            }else{
                cur -> next = head1;
                head1 = head1 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = head1 ? head1 : head2;
        return pre -> next;
    }
};

//2迭代归并
