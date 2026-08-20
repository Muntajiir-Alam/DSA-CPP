#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int minEatingSpeed(vector<int> &nums, int h)
{
    int n = nums.size();
    int maxEle = nums[0];
    for (int i = 1; i < n; i++)
    {
        maxEle = max(maxEle, nums[i]);
    }
    int i = 1, j = maxEle;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        long hr = 0;
        for (int p = 0; p < n; p++)
        {
            hr += (nums[p] + mid - 1) / mid;
        }
        if (hr <= h)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return i;
}

int main()
{
    int h = 1000000000;
    vector<int> nums = {805306368,805306368,805306368};
    cout << minEatingSpeed(nums, h) << endl;
}