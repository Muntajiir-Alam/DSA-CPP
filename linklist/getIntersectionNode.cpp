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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int n1 = 0;
    int n2 = 0;

    ListNode *tempA = headA;
    ListNode *tempB = headB;

    while (tempA != NULL)
    {
        n1++;
        tempA = tempA->next;
    }
    while (tempB != NULL)
    {
        n2++;
        tempB = tempB->next;
    }

    tempA = headA;
    tempB = headB;
    int n{abs(n1 - n2)};
    if (n1 > n2)
    {
        for (int i = 0; i < n; i++)
        {
            tempA = tempA->next;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            tempB = tempB->next;
        }
    }

    while (tempA != NULL && tempB != NULL)
    {
        if (tempA == tempB)
        {
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return NULL;
}

int main()
{
    ListNode *head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = new ListNode(4);
    head1->next->next->next->next->next = new ListNode(6);

    ListNode *head2 = new ListNode(3);
    head2->next = new ListNode(2);
    head2->next->next = head1->next->next->next;

    ListNode *ans;
    ans = getIntersectionNode(head1, head2);
    cout << ans->val << endl;
}