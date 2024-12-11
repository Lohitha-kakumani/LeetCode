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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        for(int i=0;i<n;i++){
            if(fast == NULL) return head;
            fast = fast -> next;
        }
        ListNode *slow = head;

        //if the length is exact same and we need to delet head then
        if(fast == NULL){
            ListNode *delNode = head;
            head = head ->next;
            delete delNode;
            return head;
        }

        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode *delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete delNode;
        return head;
    }
};