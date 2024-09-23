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
    ListNode* sortList(ListNode* head) {
          vector<int> arr;
    
    // Temporary pointer to
    // traverse the linked list
    ListNode* temp = head;
    
    // Traverse the linked list and
    // store node values in the vector
    while(temp!=NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    
    // Sort the array
    // containing node values
    sort(arr.begin(), arr.end());
    
    // Reassign sorted values to
    // the linked list nodes
    temp = head;
    for(int i = 0; i < arr.size(); i++){
        // Update the node's data
        // with the sorted values
        temp->val = arr[i]; 
        // Move to the next node
        temp = temp->next; 
    }
    
    // Return the head of the
    // sorted linked list
    return head; 
    }
};