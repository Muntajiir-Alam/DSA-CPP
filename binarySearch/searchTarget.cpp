#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }

        // Left half is sorted
        if (nums[i] <= nums[mid])
        {
            if (nums[i] <= target && target < nums[mid])
                j = mid - 1;
            else
                i = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (nums[mid] < target && target <= nums[j])
                i = mid + 1;
            else
                j = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {5, 1, 3};
    int target = 5;
    cout << search(nums, target) << endl;
}