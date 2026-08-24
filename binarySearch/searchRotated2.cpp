#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int i{0}, j{n - 1};
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[i] == nums[mid] && nums[mid] == nums[j])
        {
            i++;
            j--;
        }
        else if (nums[i] <= nums[mid])
        {
            // left half is sorted
            if (nums[i] <= target && target < nums[mid])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        else
        {
            // right half is sorted
            if (nums[mid] < target && target <= nums[j])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {3, 1};
    cout << search(nums, 1) << endl;
}