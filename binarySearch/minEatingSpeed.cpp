#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int minEatingSpeed(vector<int> &nums, int h)
{
    int n = nums.size();
    int i = 1, j = *max_element(nums.begin(),nums.end());
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        long hr = 0;
        for (int piles : nums)
        {
            hr += (piles + mid - 1) / mid;
            if (hr > h) break;
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
    int h = 8;
    vector<int> nums = {3,6,7,11};
    cout << minEatingSpeed(nums, h) << endl;
}