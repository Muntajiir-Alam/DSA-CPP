#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxScore(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxPoints = INT_MIN;
    // initial window sum
    int preSum = nums[0];
    for (int i = 1; i < k; i++)
    {
        preSum += nums[i];
    }
    maxPoints = max(preSum, maxPoints);

    int i = k - 1, j = n - 1;
    while (i >= 0)
    {
        preSum -= nums[i--];
        preSum += nums[j--];
        maxPoints = maxPoints = max(preSum, maxPoints);
    }
    return maxPoints;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,1};
    int k = 3;
    cout << maxScore(nums, k) << endl;
}