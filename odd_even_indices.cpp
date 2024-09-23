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
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr)
            return nullptr;
        
        if(head -> next == nullptr || head -> next -> next == nullptr){
            return head;
        }

        ListNode * even = head;
        ListNode * odd = head -> next;

        ListNode * evenPrev = even;
        ListNode * oddPrev = odd;
        head = head -> next -> next;
        int i = 2;
        
        while(head != nullptr){
            if((i % 2) == 0){
                evenPrev -> next = head;
                evenPrev = evenPrev -> next;
            }
            else{
                oddPrev -> next = head;
                oddPrev = oddPrev -> next;
            }
            i++;
            head = head -> next;
        }
        oddPrev -> next = nullptr;
        evenPrev -> next = odd;

        return even;
    }
};