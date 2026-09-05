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

ListNode *addTwoNumbers(ListNode *ls1, ListNode *ls2)
{
    ListNode dummy(0);
    ListNode *ans = &dummy;
    int rem = 0;

    while (ls1 != NULL || ls2 != NULL || rem != 0)
    {
        int sum = (ls1 ? ls1->val : 0) + (ls2 ? ls2->val : 0) + rem;
        rem = sum / 10;

        ans->next = new ListNode(sum % 10);
        ans = ans->next;

        if (ls1) ls1 = ls1->next;
        if (ls2) ls2 = ls2->next;
    }

    return dummy.next;
}

int main()
{
    ListNode *ls1 = new ListNode(3);
    ls1->next = new ListNode(2);
    ls1->next->next = new ListNode(0);
    ls1->next->next->next = new ListNode(-4);
    ls1->next->next->next->next = new ListNode(4);
    ls1->next->next->next->next->next = new ListNode(6);

    ListNode *ls2 = new ListNode(3);
    ls2->next = new ListNode(2);
    ls2->next->next = new ListNode(0);
    ls2->next->next->next = new ListNode(-4);
    ls2->next->next->next->next = new ListNode(4);

    ListNode *temp = addTwoNumbers(ls1, ls2);
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}