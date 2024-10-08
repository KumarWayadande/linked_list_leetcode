// Try to solve using tortoise-Hare method

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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode * temp = head;
        while(temp != nullptr){
            temp = temp -> next;
            len++;
        }
        // cout << "Length : " << len;
        int mid = len / 2;
        temp = head;
        for(int i = 1; i <= mid; i++)
            temp = temp -> next;

        cout << temp->val;
        return temp;
    }
};