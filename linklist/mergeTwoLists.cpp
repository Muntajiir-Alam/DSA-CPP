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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode dummy(0);
    ListNode *temp = &dummy;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    temp->next = (list1 != NULL) ? list1 : list2;

    return dummy.next;
}

int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(6);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(2);
    list2->next->next = new ListNode(3);
    list2->next->next->next = new ListNode(5);
    list2->next->next->next->next = new ListNode(6);
    list2->next->next->next->next->next = new ListNode(7);

    ListNode *merged = mergeTwoLists(list1, list2);

    while (merged != NULL)
    {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;
}