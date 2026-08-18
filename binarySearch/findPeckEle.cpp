#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    int maxIdx = 0;
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (i==j)
            return i;

        if (nums[mid] < nums[mid + 1])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }

    return maxIdx;
}
int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 4};
    cout << findPeakElement(nums) << endl;
}