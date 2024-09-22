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
    bool isPalindrome(ListNode* head) {
        
        stack<int> nodeStack;

        ListNode * temp = head;

        while(temp != nullptr){
            nodeStack.push(temp -> val);
            temp = temp -> next;
        }

        temp = head;
        while(temp != nullptr){
            int topElement = nodeStack.top();
            if(topElement != temp -> val){
                return false;
            }
            nodeStack.pop();
            temp = temp -> next;
        }

        return true;

    }
};