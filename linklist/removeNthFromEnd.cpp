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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    ListNode *curr = head;

    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return head->next;
    }
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
        curr = curr->next;
    }

    curr->next = curr->next->next;

    return head;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(6);

    ListNode *list = removeNthFromEnd(head, 2);

    while (list != NULL)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}