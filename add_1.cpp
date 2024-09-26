//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node *reverseList(Node *head)
    {
        
        if(head == NULL)
            return NULL;
        
        Node *prev = head;
        Node *curr = head->next;
        prev->next = NULL;
        while (curr != NULL)
        {
            Node *currNew = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNew;
        }

        return prev;
    }
    
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        
        if(head == NULL)
            return head;
        
        head = reverseList(head);
        Node * temp = head;
        
        int h = 0;
        
        Node * prev = head;
        int sum = 1;
        
        do{
            sum = sum +( temp -> data + h);    
            
            if(sum >= 10){
                h = 1;
            }
            else
                h = 0;
                
            temp -> data = (sum % 10);
            sum = 0;
            prev = temp;
            temp = temp -> next;
            
        }while(h != 0 && temp != NULL);
        
        if(h == 1){
            Node * newNode = new Node(h);
            prev -> next = newNode;
        }
        
        head = reverseList(head);
        
        return head;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends