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
        // int len = 0;
        // ListNode * temp = head;

        if(head == nullptr || head -> next == nullptr)
            return nullptr;

        // while(temp != nullptr){
        //     temp = temp -> next;
        //     len++;
        // }
        // temp = head;

        // if(len - n == 0)
        //     return head -> next;
        
        // for(int i = 1; i < (len - n); i++){
        //     temp = temp -> next;
        // }

        // ListNode * node = temp -> next;
        // temp -> next = node -> next;
        // delete node;

        // return head;

       ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        while (head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;

        return res->next;     

    }
};