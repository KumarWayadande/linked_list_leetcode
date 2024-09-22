/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // map<ListNode*, bool> listMap;

        if(head == nullptr || head -> next == nullptr)
            return false;


        // ListNode* temp = head;
        // while (temp != nullptr) {
        //     if (listMap[temp]) {
        //         return true;
        //     }
        //     listMap[temp] = true;
        //     temp = temp->next;
        // }





        ListNode * slow = head;
        ListNode * fast = head;

        fast = fast -> next -> next;

        while(slow && fast && fast->next != nullptr){
            if(slow == fast)
                return true;
            slow = slow->next;
            fast = fast -> next -> next;
        }
        return false;
    }
};