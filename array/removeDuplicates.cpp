#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size(), lastIdx = 1;
    int lastUnique = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i-1])
        {
            nums[lastIdx] = nums[i];
            lastIdx++;
        }
    }
    return lastIdx;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;
}