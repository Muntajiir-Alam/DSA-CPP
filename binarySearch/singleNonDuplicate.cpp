#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int i{0}, j{n - 1};
    while (i < j)
    {
        int mid{i + (j - i) / 2};
        // cheak right and left of mid
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
            (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            i = mid + 1;
        }
        else
            j = mid;
    }
    return nums[i];
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3};
    cout << singleNonDuplicate(nums) << endl;
}