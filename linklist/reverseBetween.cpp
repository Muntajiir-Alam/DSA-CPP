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

ListNode *reverseBetween(ListNode *head, int left, int right)
{

    if (head == NULL || head->next == NULL || left == right)
        return head;

    ListNode *l, *temp = head;

    //  reverse pointer
    ListNode *startPos;  // point at reverse of first node
    ListNode *prev = NULL;
    ListNode *next = NULL;

    for (int i = 1; i < right + 1; i++)
    {
        if (left - 1 == i)
        {
            l = temp;
        }
        if (i == left)
            startPos = temp;

        if (i >= left && i <= right)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        else
            temp = temp->next;
    }
    if (left == 1 && temp == NULL)
        return prev;
    if (left - 1 > 0)
        l->next = prev;
    startPos->next = next;
    return left == 1 ? prev : head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode *temp = reverseBetween(head, 1, 2);
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}