#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxOnes = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            count++;
        else
            count = 0;

        maxOnes = max(maxOnes, count);
    }
    return maxOnes;
}
int main()
{
    vector<int> nums = {1, 0, 1, 1, 0, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;
}