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

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *newHead = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;

    return newHead;
}
int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(6);

    ListNode *res = reverseList(head);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}