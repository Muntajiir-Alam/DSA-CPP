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
        this->next = nullptr;
    }
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || k <= 1)
        return head;

    // Dummy node
    ListNode dummy(0);
    dummy.next = head;

    ListNode *groupPrev = &dummy;

    while (true)
    {
        // 1. Find the kth node
        ListNode *kth = groupPrev;

        for (int i = 0; i < k; i++)
        {
            kth = kth->next;

            if (kth == nullptr)
                return dummy.next;
        }

        // 2. Save the node after the group
        ListNode *groupNext = kth->next;

        // 3. Reverse the group
        ListNode *prev = groupNext;
        ListNode *curr = groupPrev->next;

        while (curr != groupNext)
        {
            ListNode *next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 4. Connect previous part to reversed group
        ListNode *oldFirst = groupPrev->next;

        groupPrev->next = kth;

        // 5. Move groupPrev to the end of reversed group
        groupPrev = oldFirst;
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

    reverseKGroup(head, 2);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}