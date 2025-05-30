
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while(second && second -> next){
            first = first -> next;
            second = second -> next -> next;
        }
        return first;
    }
};