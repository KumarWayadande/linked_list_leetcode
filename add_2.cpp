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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int h = 0;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while (temp1 && temp2) {
            int sum = (temp1->val + temp2->val) + h;
            h = sum / 10;
            int digit = sum % 10;

            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = newNode;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 || temp2) {
            if (temp2)
                temp1 = temp2;

            while (temp1) {
                int sum = temp1->val + h;
                h = sum / 10;
                int digit = sum % 10;

                ListNode* newNode = new ListNode(digit);
                temp->next = newNode;
                temp = newNode;

                temp1 = temp1->next;
            }
        }

        if (h == 1) {
            ListNode* node = new ListNode(1);
            temp->next = node;
        }
        return head->next;
    }
};