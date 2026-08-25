#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMin(vector<int> &nums)
{
    /*
    Input: nums = [3,1,1]
    Output: 1
    */

    int n = nums.size();
    int i{0}, j{n - 1};
    int minEle{nums[i]};
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[i] == nums[mid] && nums[mid] == nums[j])
        {
            minEle = min(minEle, nums[i]);
            i++;
            j--;
        }
        else if (nums[i] <= nums[mid])
        {
            // left half is sorted
            minEle = min(minEle, nums[i]);
            i = mid + 1;
        }
        else
        {
            // right half is sorted
            minEle = min(minEle, nums[mid]);
            j = mid - 1;
        }
    }
    return minEle;
}
int main()
{
    vector<int> nums = {3,1};
    cout << findMin(nums) << endl;
}