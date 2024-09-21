#include <iostream>
using namespace std;

class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int data, ListNode * next){
        this->val = data;
        this->next = next;
    }
};

class Solution
{
public:
    static ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *curr = head->next;
        prev->next = nullptr;
        while (curr != nullptr)
        {
            ListNode *currNew = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNew;
        }

        return prev;
    }
};

int main()
{
    ListNode *ls5 = new ListNode(5, nullptr);
    ListNode *ls4 = new ListNode(4, ls5);
    ListNode *ls3 = new ListNode(3, ls4);
    ListNode *ls2 = new ListNode(2, ls3);
    ListNode *ls1 = new ListNode(1, ls2);

    ListNode *temp = ls1;

    while (temp != nullptr)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }

    temp = Solution ::reverseList(ls1);

    while (temp != nullptr)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }
    return 0;
}