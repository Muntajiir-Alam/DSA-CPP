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

void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    // Find the middle
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode *second = slow->next;
    slow->next = nullptr;

    ListNode *prev = nullptr;

    while (second != nullptr)
    {
        ListNode *next = second->next;
        second->next = prev;
        prev = second;
        second = next;
    }

    // Merge both halves
    ListNode *first = head;
    second = prev;

    while (second != nullptr)
    {
        ListNode *firstNext = first->next;
        ListNode *secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        first = firstNext;
        second = secondNext;
    }
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(6);

    reorderList(head);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
};