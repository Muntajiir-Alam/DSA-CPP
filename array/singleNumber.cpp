#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n-1; i += 2)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }
    return nums[n-1];
}
int main()
{
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums) << endl;
}