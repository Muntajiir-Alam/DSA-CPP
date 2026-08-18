#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (i == j)
            return nums[i];

        if (nums[mid] > nums[j])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {3,4,5,1,2};
    cout << findMin(nums) << endl;
}