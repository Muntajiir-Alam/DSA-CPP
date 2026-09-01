#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{

    ListNode *head = new ListNode(3);

    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = new ListNode(4);
    // Print before reverse
    cout << "Before reverse: ";
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";

    head = reverseList(head);

    // Print after reverse
    cout << "After reverse: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
    reverseList(head);


}