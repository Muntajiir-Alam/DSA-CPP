#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxEle{INT_MIN}, sum{0};
    for (auto &&i : nums)
    {
        maxEle = max(maxEle, i);
        sum += i;
    }
    int i{maxEle}, j{sum};
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        int curSum{0};
        int splits{0};
        // 7,2,5,10,8
        for (auto &&i : nums)
        {
            curSum += i;
            if (curSum > mid)
            {
                splits++;
                curSum = i;
            }
            if (splits > k)
                break;
        }
        splits++;
        if (splits <= k)
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
    vector<int> nums = {7, 2, 5, 10, 8};
    cout << splitArray(nums, 2) << endl;
}