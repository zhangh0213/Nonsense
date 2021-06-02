/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//判断链表中是否存在环
//使用快慢指针，如果存在环，那么两个指针将会相遇，否则不会
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(fast && slow){
            if(fast == slow){
                return true;
            }
            if(fast -> next){
                fast = fast -> next;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        return false;
    }
};
