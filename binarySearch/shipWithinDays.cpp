#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
using namespace std;

/*
    Input: weights = [1,2,3,1,1], days = 4
    Output: 3
    Explanation:
    1st day: 1
    2nd day: 2
    3rd day: 3
    4th day: 1, 1
*/

int shipWithinDays(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = *max_element(nums.begin(), nums.end());
    int j = accumulate(nums.begin(), nums.end(), 0);
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        int days = 1, curCap = 0;

        for (int idx = 0; idx < n; idx++)
        {
            if (curCap + nums[idx] > mid)
            {
                days++;
                curCap = 0;
            }
            curCap += nums[idx];
        }

        if (days > k)
            i = mid + 1;
        else
            j = mid;
    }
    return i;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipWithinDays(nums, 5) << endl;
}