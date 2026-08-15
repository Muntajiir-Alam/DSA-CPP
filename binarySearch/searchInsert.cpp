#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{

    int i = 0;
    int j = nums.size() - 1;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] < target)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return i;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int k = 7;
    cout << searchInsert(nums, k) << endl;
}