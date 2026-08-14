// 239
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();

    int i = 0;
    int curSum = 0;
    int minLen = INT_MAX;

    for (int j = 0; j < n; j++)
    {
        curSum += nums[j];

        while (curSum >= target)
        {
            minLen = min(minLen, j - i + 1);

            curSum -= nums[i];
            i++;
        }
    }

    if (minLen == INT_MAX)
        return 0;

    return minLen;
}

int main()
{
    vector<int> nums = {1, 4, 4};
    cout << minSubArrayLen(4, nums) << endl;
}