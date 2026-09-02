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
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = head;

    while (temp != NULL && temp->next !=  NULL)
    {
        temp = temp->next;
        if (temp->val > prev->val)
        {
            prev->next = temp;
            prev = prev->next;
        }
    }
    prev->next = NULL;
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    // head->next->next->next->next->next = new ListNode(;

    ListNode *distinctLL = deleteDuplicates(head);

    while (distinctLL != NULL)
    {
        cout << distinctLL->val << " ";
        distinctLL = distinctLL->next;
    }
    cout << endl;
}