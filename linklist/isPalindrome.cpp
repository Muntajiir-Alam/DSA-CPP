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

bool isPalindrome(ListNode *head)
{
    if (head->next == NULL)
        return true;

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    ListNode *left = prev;
    ListNode *right = (fast != NULL) ? slow->next : slow;

    while (left != NULL && right != NULL)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(0);

    cout << isPalindrome(head) << endl;
}