#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxElement(vector<int> &nums, int maxi, int idx)
{
    if (nums.size() == idx)
        return INT_MIN;
    return max(nums[idx] , maxElement(nums, maxi , idx + 1));
}
int main()
{
    vector<int> nums = {1,2,3,-3};
    cout << maxElement(nums, nums[0], 0) << endl;
}